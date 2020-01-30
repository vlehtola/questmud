inherit "guilds/guilds/guild";
inherit "room/room";
#define WARLOCK_D "/daemons/warlock_d"
mapping sacrifices;
reset(arg) {
  sacrifices = ([ ]);
  load_plaque();
  if(arg) return;
  short_desc = "The Warlocks Guild";
  long_desc = "This area is quite dark, being lit only by one dim glow globe which is suspended from the ceiling "+
"in the center of the room.  Directly beneath the globe is a statue of a strikingly beautiful "+
"but cruel looking woman whose smile reveals two large fangs.  It could very well be mistaken "+
"for a vampire, but is in fact a representation of the goddess Eonptey.  The statue is made of "+
"black marble with faint streaks of red running through it. The statue is somehow magical looking "+
"and its is constantly looking people in this dark place. In front of that statue is a black altar "+
"which is full of blood stains.\n";
  add_exit("north","/guilds/warlock/cathedral/room5");
  add_exit("west","/guilds/warlock/cathedral/room9");
  add_exit("east","/guilds/warlock/cathedral/room10");
  items = allocate(4);
  items[0] = "altar";
  items[1] = "The altar seems to made from somekind of black marble.\nOn the altar reads: worship, sacrifice, invite";
  items[2] = "statue";
  items[3] = "The status is made from black marble with faint streaks of red running thourgh it. It feels quite cold";
  set_not_out(1);
  set_light(3);
  move_object(clone_object("/daemons/warlockboard"), this_object());
}

init() {
  ::init();
  guild_init();
  add_action("do_worship", "worship");
  add_action("do_sacrifice", "sacrifice");
  add_action("do_invite", "invite");
}

do_invite(string str) {
object ob;
if(!this_player()->query_wiz()) {
write("You are not the elder of warlock guild.\n");
return 1;
}

if(!str) {
write("Invite who?\n");
return 1;
}

ob = find_player(str);
if(!ob) {
write("No such player currently in game.\n");
return 1;
}

if(WARLOCK_D->query_invite(lower_case(str)) == 1) {
write(capitalize(str)+" is no longer invited to warlock guild.\n");
WARLOCK_D->add_invite(str,0);
return 1;
}

write("You invite "+capitalize(str)+" to the warlock guild.\n");
WARLOCK_D->add_invite(lower_case(str),1);
return 1;
}

do_sacrifice(string str) {
object ob;
int i;
int pois;
int lappa;
if(this_player()->query_alignment() >= 0) {
write("A dark voice says: Now feel my wrath, you wrong believer!\n");
this_player()->death();
return 1;
}
ob = present("warlock_pendant", this_player());
if(!ob) {
        write("A dark voice says: One wrong move and I will banish you to eternal hell!\n");
        return 1;
}

if((ob->query_souls()<0) || (ob->query_souls()>2000000)) 
  { // Goddamn warlock antiabuse code --N
    ob->set_souls(0);
  }

if(!str) { write("A dark voice says: Sacrifice what?\n"); return 1; }

if(sscanf(str, "%d", i) != 1) {
        write("A dark voice says: Sacrifice <amount> perhaps?\n");
        return 1;
}

if(i<0 || i>30000)      {
        write("A sharp shock of pain runs through your body.\n");
        return 1;
                        }

if(ob->query_souls() < i) {
        write("A dark voice says: We don't accept small sacrifices!\n");
        return 1;
}
if(query_sacrifices(this_player()->query_real_name())) {
        write("The dark gods don't accept your sacrifices just yet!\n");
        return 1;
}
lappa = (this_player()->query_skills("soul channeling")+100)/2;
pois = i/4;
pois = (pois * 100) / lappa;
i = i-pois;
if(i<0)i=0;
write("You kneel down to the altar and sacrifice souls from your pendant to the dark gods.\n");
say(this_player()->query_name()+" kneels down to the altar and makes a sacrifice to the dark gods.\n");
write("You feel like the gods accepted "+i+" souls.\n");
add_sacrifice(this_player()->query_real_name(), 1);

ob->reduce_souls(i+pois);
WARLOCK_D->add_souls(this_player()->query_real_name(), i);
return 1;
}
add_sacrifice(string str, int i) {
sacrifices[str] = i;
}

query_sacrifices(string str) {
        return sacrifices[str];
}

do_worship() {
string str;
int i;
int pexp, mexp;
write("You kneel down to the altar and chant a prayer for the dark gods.\n");
say(this_player()->query_name()+" kneels down to the altar and chants a prayer.\n");
if(this_player()->query_alignment() >= 0) {
write("A dark voice says: Now feel my wrath, you wrong believer!\n");
this_player()->death();
return 1;
}
pexp = WARLOCK_D->query_demon_xp(this_player()->query_real_name()) / 100000;
mexp = 1000000000 / 100000;
i = (pexp * 100) / mexp;
write("PROSSA ON "+i+".\n");
switch(i) {
case 0..1: str = "Initiate of the Third Circle"; break;
case 2..3: str = "Member of the Third Circle"; break;
case 4..6: str = "Adept of the third Circle"; break;
case 7..10: str = "Master of the Third Circle"; break;
case 11..15: str = "Candidate of the Second Circle"; break;
case 16..20: str = "Member of the Second Circle"; break;
case 21..25: str = "Elder of the Second Circle"; break;
case 26..35: str = "Ruler of the Second Circle"; break;
case 36..50: str = "Servant of the First Circle"; break;
case 51..75: str = "Follower of the First Circle"; break;
case 76..90: str = "Member of the First Circle"; break;
case 91..99: str = "Elder of the First Circle"; break;
case 100: str = "Overlord of the Warlocks"; break;
}
write("A dark voice says: You are a "+str+".\n");
write("You have sacrificed total of "+WARLOCK_D->query_souls(this_player()->query_real_name())+" souls to the chaos.\n");
write("As you stand up, you feel the dark gods are pleased with you!\n");
return 1;
}

guild_max_level() {
  return 20;
}

guild_name() {
    return "Warlocks";
}

check_joining_rec() {
        if(this_player()->query_alignment() >=0) {
        write("We don't wan't you goodies here!\n");
        return 0;
    }
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;
}

get_bonuses(level) {
  return "con 2 , int 3 , ";
}

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  skill += (["essence of chaos":guild_level*2]); //40%
  skill += (["cast forge of chaos":guild_level*1]); //20%
  skill += (["knowledge of summoning":guild_level*3]); //60%
  skill += (["knowledge of chaos":guild_level*2]); //40%
  skill += (["cast plane of chaos":guild_level*4]); //80%
  skill += (["cast chaos sheltering":guild_level*3]); //60%
  skill += (["cast beast control":guild_level*4]); // 80%
  skill += (["cast aid of chaos":guild_level*2]); // 40%
  skill += (["cast warmth of chaos":guild_level*3]); // 60%
  skill += (["cast lesser chaos":guild_level*4]); // 80%
  skill += (["attack":guild_level*5]); // 100%
  skill += (["kick":guild_level*5]); // 100%
  skill += (["cast anvil of chaos":guild_level*2]); // 40%
  skill += (["consider demon":guild_level*5]); // 40%
  return skill;
}

special_advance_effect(lvl) {
    object pendant;
    if (!present("warlock_pendant", this_player())) {
write("A dark voice echoes in your head: Take this pendant and collect souls to me!\n");
write("Then suddenly a portal appears and some-one gives you pendant.\n");
    pendant = clone_object("/guilds/warlock/obj/pendant");
    move_object(pendant, this_player());
return 1;
}
}
