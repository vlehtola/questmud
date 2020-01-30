#define SAVE_FILE "/data/demon_xp"
#define STACK_D "/daemons/string_stack_d"
#define MAX_XP 1000000000
#define MAX_SOULS 10000000
mapping demon_xp;
mapping souls;
mapping tasks;
static invite;
static is_demon;
static string * rem_say(string arg,string * arr);
static status last_say(string *arr);

status do_say(string str, object who) {
  int i;
  object *ob;
  string *last_tell;

  if(!str)   {
    write("Syntax : say <message or 'last'>");
    return 1;
  }
ob = all_inventory(environment(who));
for(i=0;i<sizeof(ob);i++) {
 if(ob[i]!=who && living(ob[i]))
 ob[i]->set_say_messages(rem_say(sprintf("["+ctime()[11..15]+"] %s says '%s'\n",who->query_name(),str), ob[i]->query_say_messages()));
 }
  tell_room(environment(who), who->query_name() + " says '" +str+ "'\n");
  return 1;

}
do_kill(string str, object who) {
    object ob;
    if (who->check_condis()) { return 1; }
    if (!str) {
        do_say("what i am suppose to attack?", who);
    return 1;
    }
    if (environment(who)->query_property("no_kill")) {
      do_say("I can't attack anybody in here.", who);
      return 1;
    }
    ob = present(lower_case(str), environment(who));
    if (!ob) {
       do_say("No " + str + " here !",who);
        return 1;
    }
    if (!living(ob)) {
       do_say(capitalize(str) + " is not a living thing!",who);
        return 1;
    }
    if (ob == this_object()) {
    do_say("Go to hell\n",who);
        return 1;
    }
    if (who->query_attacker() == ob) {
    do_say("I am already attacking that one!",who);
        return 1;
    }
    say(who->query_name() + " attacks " + ob->query_name() + "!\n",who);
    who->attack_object(ob);
    return 1;
}

do_follow(object who) {
if(!who->query_follow()) {
do_say("I will now follow you my master.",who);
who->set_follow(1);
return 1;
}
do_say("I will now wait you here my master.",who);
who->set_follow(0);
return 1;
}
do_spell(string str, object ob) {
    int sp_boost;
    string class;
    object who;
    who = ob;
    if(!who)who=this_player();
    if (who->check_condis()) { return 1; }
    if (!str) {
        tell_object(who, "You are boosting offensive spells with "+who->query_sp_boost(1)+ " sp.\n");
        tell_object(who, "See 'help cast' for more information.\n");
        return 1;
    }
    if (str == "stop") {
        if (who->query_spell()) {
            tell_object(who, "You interrupt your spell.\n");
            who->query_spell()->interrupt_spell();
            return 1;
        }
        else {
            tell_object(who, "You are not casting anything.\n");
            return 1;
        }
    }
    if (sscanf(str, "%s %d", class, sp_boost) == 2) {
        if (class == "offensive") {
           if (sp_boost < 1 || sp_boost > who->query_max_sp()/4) {
             tell_object(who, "Your minimum sp boost is 1 and maximum is "+(who->query_max_sp()/4)+".\n");
             return 1;
           }
           if(who->query_spell()) {
                tell_object(who, "Cannot change boost while casting.\n");
                return 1;
           }
           who->set_sp_boost("offensive", sp_boost);
           tell_object(who, "Setting your offensive boost to "+sp_boost+" sp.\n");
           call_other("/guilds/obj/boost.c", "offensive_boost", sp_boost, 1);
           return 1;
        }
        write("No such a boost class. See 'help cast'.\n");
        return 1;
    }
    if (environment(who)->query_property("no_spell") ||
        present("amf",environment(who)) &&
        present("amf",environment(who))->query_amf()) {
      tell_object(who, "A mystical force interrupts your concentration.\n");
      return 1;
    }
    if (who->query_spell()) {
        tell_object(who, "You interrupt your previous spell and start a new one.\n");
        destruct(who->query_spell());
    }
    if(who->query_use_skill()) {
       tell_object(who, "You interrupt your skill and start casting a spell.\n");
        destruct(who->query_use_skill());
    }
    if(who->query_sp() == 0) {
	tell_object(who, "You don't have enough spellpoints to start casting.\n");
	do_say("I don't have enough spellpoints to start casting anything.\n", who);
	return 1;
    }
    who->remove_invisibility();
    who->set_spell(clone_object("/guilds/obj/spell"));
    if(who->query_spell())
       who->query_spell()->start_spell(str, who);
    return 1;
}

do_skill(string str, object who) {
object skill, spell;
skill = who->query_use_skill();
spell = who->query_spell();
if(who->check_condis()) { return 1; }
if(environment(who)->query_property("no_skill")) {
  do_say("I can't use skills in here.\n",who);
  return 1;
}
if(who->query_ep() < 1) {
  do_say("I don't have enough endurance points.\n", who);
  return 1;
}

if (!str) {
 do_say("What skill should i use?\n",who);
 return 1;
}

if (str == "stop") {
  if (skill) {
   do_say("I stopped my skill attempt.\n",who);
    skill->interrupt_skill();
    return 1;
    } else {
      do_say("I am not doing anything.\n",who);
      return 1;
    }
  }
  if (skill) {
    do_say("Ok iam starting new skill.\n", who);
    destruct(skill);
  }
  if (spell) {
    do_say("I stopped my spellcasting.\n",who);
    destruct(spell);
   }
  skill = clone_object("/guilds/obj/skill");
  who->set_use_skill(skill);
  skill->start_skill(str, who);
  return 1;
}


do_get(string str, object who) {
  string item;
  string container;
  object item_o, ob, pl;
  pl = who;
  if (pl->check_condis()) { return 1; }
  if (!str) {
    do_say("What i should take?", pl);
    return 1;
  }
  if (sscanf(str, "%s from %s", str, container) == 2) {
    ob = present(container, pl);
    if(!ob) ob = present(container, environment(pl));
    if (!ob) {
      do_say("There is no " + container + " here.", pl);
      return 1;
    }
    if (!call_other(ob, "can_put_and_get", 0)) {
      do_say("I can't get anything from there.", pl);
      return 1;
    }
  }
  if (!ob) { ob = environment(pl); }
  item_o = call_other("/daemons/filter", "EQ_FILTER", str, ob);
  if(!item_o) {
    do_say("Nothing taken.", pl);
    return 1;
  }
  get_all(item_o, pl, ob);
  pl->fix_weight();
  return 1;
}
status can_get_item(object ob, object who) {
  if(!ob->get()) return 0;
  return 1;
}

get_all(object *list, object pl, object container_ob) {
  int i;
  string *kamat, lista;
  list = filter_array(list, "can_get_item");
  kamat = allocate(sizeof(list));
  for(i=0; i < sizeof(list); i++) {
    kamat[i] = list[i]->short();
    move_object(list[i], pl);
    if(container_ob) container_ob->add_weight( - list[i]->query_weight());
  }
  lista = STACK_D->stack_item_list(kamat);
  if(!lista) {
   do_say("Nothing taken.", pl);
    return 1;
  }
  tell_room(environment(pl), pl->query_name()+" takes "+lista+".\n", ({ pl, }));
  if(container_ob->automatic_weight()) {
  container_ob->calc_weight();
}
return 1;
}

do_drop(string str, object arg) {
  object item_o;
  int i;
  if (arg->check_condis()) { return 1; }
  if (!str) { do_say("Drop what?\n",arg); return 1; }
  item_o = call_other("daemons/filter", "EQ_FILTER", str, arg);
  if (arg) {
    while(i < sizeof(item_o)) {
      if (item_o[i]->query_auto_load()) { destruct(item_o[i]); }
      i += 1;
    }
  }
  if(!arg) arg = this_object();
  if(!item_o) {
    do_say("Nothing dropped.",arg);
    return 1;
  }
  drop_all(item_o, arg);
  arg->fix_weight();
  return 1;
}


status can_drop_item(object ob) {
  int d;
  if(!ob) return 0;
  d = ob->drop();
  if(!ob || d) return 0;
  ob->stop_wearing(1); //silently
  return 1;
}

drop_all(object *list, object pl) {
  int i;
  string *kamat, lista;
  list = filter_array(list, "can_drop_item");
  kamat = allocate(sizeof(list));
  for(i=0; i < sizeof(list); i++) {
    kamat[i] = list[i]->short();
    move_object(list[i], environment(pl));
  }
  lista = STACK_D->stack_item_list(kamat);
  if(!lista) {
    do_say("Nothing dropped.",pl);
    return 1;
  }
  tell_room(environment(pl), pl->query_name()+" drops "+lista+".\n", ({ pl, }));
  pl->fix_weight();
  return 1;
}
string * rem_say(string arg, string * arr){
  int x;
  if(!pointerp(arr)) arr = ({});
  if(!arg) return 0;
  if(sizeof(arr)>19) {
    for(x=1;x<sizeof(arr);x++) {
      arr[x-1]=arr[x];
    }
    arr[19]=arg;
    return arr;
  }
  arr += ({ arg });
  return arr;
}

last_say(string *arr) {
  int x;
  if(!pointerp(arr)) return 1;
  for(x=0;x<sizeof(arr);x++)
  {
    printf("%s",arr[x]);
  }
  return 1;
}

reset(arg) {
  if(arg) return;
  demon_xp = ([ ]);
  is_demon = ([ ]);
  souls = ([ ]);
  invite = ([ ]);
  tasks = ([ ]);
  if(!restore_object(SAVE_FILE)) {
  save_object(SAVE_FILE);
  }
}
add_invite(string str, int i) {
invite[str] = i;
}
query_invite(string str) {
	return invite[str];
}
query_tasks(string who, string task) {
if(tasks[who] == task) { return 1; }
return 0;
}
add_tasks(string who, string task) {
	tasks[who] += task;
	save_object(SAVE_FILE);
	write("jees task onnistu.\n");
	return 1;
}
add_demon_xp(string str, int i) {
	if(demon_xp[str] > MAX_XP)return;
	demon_xp[str] += i;
	save_object(SAVE_FILE);
}
add_souls(string str, int i) {
if(souls[str] > MAX_SOULS)return;
souls[str] += i;
save_object(SAVE_FILE);
}

reduce_souls(string str, int i) {
souls[str] -= i;
save_object(SAVE_FILE);
say("You can see the souls hoovering in this place as "+capitalize(str)+" draws something from the planes of chaos.\n");
}
query_souls(string str) { return souls[str]; }

reduce_demon_xp(string str, int i) {
	demon_xp[str] -= i;
	if(demon_xp[str] < 0) {
	demon_xp[str] = 0;
    }
	save_object(SAVE_FILE);
}
query_demon_xp(string str) {
	return demon_xp[str];
}
add_demon(string str, int i) {
	is_demon[str] = i;
}

query_demon(string str) {
	return is_demon[str];
}
summon_demon(string str, int power) {
int chance;
int plus;
chance=this_player()->query_skills("knowledge of summoning")/5;
chance+=this_player()->query_skills("demonology")/5;

if(str == "minor" &&  query_demon_xp(this_player()->query_real_nam()) < 100000000) {
write("A somekind of hollow dark voice says in your head: You can't call that kind of demons just yeat!\n");
return 1;
}
if(str == "greater" &&  query_demon_xp(this_player()->query_real_nam()) < 600000000) {
write("A somekind of hollow dark voice says in your head: You can't call that kind of demons just yeat!\n");
}
if(query_demon(this_player()->query_real_name())) {
	write("You already have demon.\n");
	return 1;
}
if(environment(this_player())->query_summon_circle()) {
write("This place makes the summoning much easier.\n");
plus=50;
}

switch(str) {
	case "lesser": chance-=10; break;
	case "minor": chance-=20; break;
	case "greater": chance-=30; break;
}
chance+=power+plus;
if(random(chance) < random(200)) {
	write("You fail at the summoning ritual\n");
	say(this_player()->query_name()+" fails the summoning ritual.\n");
	return 1;
}
write("You summon something from the planes of hell.\n");
say(this_player()->query_name()+" summons something from the planes of hell.\n");
if(random(this_player()->query_skills("knowledge of summoning")) < random(200) && !this_player()->query_chaos_aura() && !environment(this_player())->query_summon_circle()) {
write("The demon looks at you with an angry look on its face and attacks!\n");
say("The face of demon makes you feel scare as it looks at "+this_player()->query_name()+" with hatred look on its face.\n");
this_player()->death();
return 1;
}
get_demon(str);
if(power) {
write("You spend some of the souls to boost the summoning.\n");
}
}
/* demons?
punisher | executioner |
*/
get_short(string str) {
int i;
i = query_demon_xp(this_player()->query_real_name());
switch(query_demon_xp(this_player()->query_real_name())) {
case 0..5000000: return "Scavenger Demon";
case 5000001..10000000: return "Punisher Demon";
case 10000001..20000000: return "Executioner Demon";
case 20000001..50000000: return "Spawn Demon";
case 50000001..75000000: return "Blood Demon";
case 75000001..100000000: return "Torturer Demon";
case 100000001..175000000: return "Spike Demon";
case 175000001..300000000: return "Horn Demon";
case 300000001..500000000: return "Wicked Demon";
case 500000001..750000000: return "Reaver Demon";
case 750000001..900000000: return "Chaos Demon";
case 900000001..999999999: return "Demon Lord";
case 1000000000: return "Arch-Demon";
}
return "A Demon";
}

get_long(string str) {
switch(str) {
case "Scavenger Demon": return "This is the lowest of demons. It looks like a somekind of animal with "+
"horned bones sticking out of its body. The scavenger is walking with four legs what are twisted and "+
"bloody. The skin of this demon is ragged from the battles that this demon has to fight to survive. "+
"It looks like this demon aren't the smartest or wisest of the demon. It have a poor fighting abilities and "+
"sometimes it can even attack its master because of the insticts of animals";

case "Spawn Demon": return "This is a famous and feared spawn demon, summoned from the deepest pits of "+
"chaos. Ground trembles and shakes as it walks around or just changes it's standing position. This demon "+
"has no wings or tail as demons usually have. Wings and tail are compensated by it's enormous fists, big "+
"enough to smash down houses or just to crush tiny little beings on it's way. Darkness and chaos surrounds "+
"this being, protecting it and giving strength to it. There is no weak spots in it's body, you can only see "+
"muscles all over, coloured deep red, or maybe it's blood, who knows? There are no rumours heard about "+
"these demons, maybe no one has before met this type, or maybe no one has lived to tell those tales";

case "Punisher Demon": return "This horrible demon from inner circles of hell is pulsating with chaotic "+
"powers. It's skin is the deepest red you've seen and it looks extremely hot. "+
"The demon also has a tall tail which it swings around looking for something to "+
"smash, tail consist of long, about two feet long hairy part and at the end it "+
"divides into three spikes. As you progress along checking the demon, it only "+
"gets worse. His head is purely inhuman, two unimaginably black eyes stare deep "+
"from demons face, mouth of the demon is just a hole in the middle of the face "+
"with razorshap tooths surrounding it and going in it. It's hooves are atleast "+
"four times the size of normal human feet. The name punisher demon must come "+
"from it's way to slash it's tail like a whip";

case "Executioner Demon":
return "The thing which separates this demon from others must be it's horribly lust "+
"for blood and gore. It's hands are shaped axe-like and it can swing those with "+
"enormous strength. This demon does not have tail like most of other demon "+
"species, but this makes it up with brute power. It has two almost two feet "+
"long spiral thorns growing from it's forehead. This demon is extremely "+
"musculous compares to other lesser demons and will surely be the king of the "+
"hill within them. The demon's body is covered with black fur, but underneath "+
"the fur glows it's skin bright red";

case "Chaos Demon":
return "The power of this demon is absolutely godly. It is black as obsidian and the "+
"skin looks like crafted from stone. It has huge wings connected to arms, which "+
"it can use to protect itself from allkind of weapons. Three extremely ugly red "+
"eyes stare to eternity. It is the most human of the demon species which may "+
"have made it to be the ultimate race of the demons. This demon is around 20 "+
"feet tall. Claws of  this ultimate chaos demon are steel-like and look like "+
"those could cut any kind of materials";
}
return "This demon is without a descs(Rewards for good ones)";

}

get_level(string str, string st) {
	int i;
	i = 1;
	i += random(4);
	if(str == "lesser") { i+=3; }
	if(str == "minor") { i+=6; }
	if(str == "greater") { i+=9; }
	if(st == "Scavenger Demon") { i+=3; } //10|15|20
	if(st == "Punisher Demon") { i+=6; } //10|15|20
	if(st == "Executioner Demon") { i+=9; }
	if(st == "Spawn Demon") { i+=12; }
	if(st == "Blood Demon") { i+=15; }
	if(st == "Torturer Demon") { i+=18; }
	if(st == "Spike Demon") { i+=21; }
	if(st == "Horn Demon") { i+=24; }
	if(st == "Wicked Demon") { i+=27; }
	if(st == "Reaver Demon") { i+=30; }
	if(st == "Chaos Demon") { i+=33; }
	if(st == "Demon Lord") { i+=36; }
	if(st == "Arch-Demon") { i+=42; }
	if(i>50)i=50;
	return i;
}
get_stats(string str) {
int i;
i = this_player()->query_skills("knowledge of chaos")/2;
i += this_player()->query_skills("knowledge of summoning")/2;
i = i+random(i);
return i;
}

get_demon(string str) {
int dstr, ddex, dcon, dint, dwis;
object demon;
demon = clone_object("/guilds/warlock/obj/demon");
move_object(demon, environment(this_player()));
dstr = get_stats("str");
ddex = get_stats("dex");
dcon = get_stats("con");
dint = get_stats("int");
dwis = get_stats("wis");
demon->set_name("demon");
demon->set_short("A "+str+" "+get_short(str));
demon->set_long(get_long(get_short(str))+".\nIt is a demon.\n");
demon->no_money();
demon->set_level(get_level(str, get_short(str)));
demon->set_random_pick(0);
demon->set_str(dstr+demon->query_level());
demon->set_dex(ddex+demon->query_level());
demon->set_con(dcon+demon->query_level());
demon->set_int(dint+demon->query_level());
demon->set_wis(dwis+demon->query_level());
demon->set_al(-100);
demon->set_al_aggr(200);
demon->set_controller(this_player()->query_real_name());
add_demon(this_player()->query_real_name(), demon);
demon->set_epreg(this_player()->query_ep_regen()+100);
demon->set_spreg(this_player()->query_sp_regen()+100);
demon->set_hpreg(this_player()->query_hp_regen());
if(demon->query_max_hp() > 4000) {
demon->set_max_hp(4000);
}
if(demon->query_max_ep() > 1000) {
demon->set_max_hp(1000);
}
if(demon->query_max_sp() > 6000) {
demon->set_max_hp(6000);
}
demon->set_skills("chaos strike", demon->query_level()*2+20);
demon->set_skills("kick", demon->query_level()*5+20);
demon->set_skills("torch creation", demon->query_level()*4+10);
demon->set_skills("hunting", demon->query_level()*3+10);
demon->set_skills("fire building", demon->query_level()*2+10);
demon->set_skills("punch", demon->query_level()*2+30);
demon->set_skills("bare hands", demon->query_level()*2+30);
demon->set_skills("chaos bludgeons", demon->query_level()*2+30);
demon->set_skills("chaos blades", demon->query_level()*2+20);
demon->set_skills("chaos axes", demon->query_level()*2+10);
demon->set_skills("attack", demon->query_level()*2+50);
demon->set_skills("doublehit", demon->query_level()*2+20);
demon->set_skills("cast plane of chaos", demon->query_level()*2+50);
demon->set_skills("cast forge of chaos", demon->query_level()*2+50);
demon->set_skills("cast anvil of chaos", demon->query_level()*2+50);
demon->set_skills("cast blessing of chaos", demon->query_level()*2+30);
demon->set_skills("cast void travel", demon->query_level()*2+30);
demon->set_skills("essence of chaos", demon->query_level()*3+20);
demon->set_skills("cast lesser chaos", demon->query_level()*3+30);
demon->set_skills("cast minor chaos", demon->query_level()*3+20);
demon->set_skills("cast greater chaos", demon->query_level()*3+10);
}
/*
Skills
demonology              castaus nopeutus
Knowledge of chaos      allaround skill
Knowledge of summoning  auttaa demonin summonnaamisessa
chaos strike            offensive toimii vaan warlock wepoilla


First spell
cast draw chaos        dcs


Second round spell
cast aura of menace     aum
cast chaos demon        cad
cast chaos blessing     cab
cast cure evil          cel
cast chaos weapon       cwe
cast boost chaos weapon bcw
cast chaos plane        cpl

Third round spell
cast lesser chaos       lec
cast minor chaos        mic
cast greater chaos      grm



spells lappa
dcs aum lec -> tekee tekee eraan nakosen copin mika suojaa playeria kun se koittaa summonia demonia
dcs aum mic -> prottaa demonin shieldilla
dcs aum grm -> prottaa demon hplinkilla

dcs cad lec -> koittaa tehda lesser demonin
dcs cad mic -> koittaa tehda minor demonin
dcs cad grm -> koittaa tehda greater demonin

dcs cel lec -> healaa demonia pikkuhealilla
dsc cel mic -> healaa demonia isomallla healilla
dsc cel grm -> healaa demonia �SOLLA HEALILLA

dcs cwe lec -> callaa chaos bludgeonin
dcs cwe mic -> callaa chaos swordin
dcs cwe grm -> callla chaos axen

dcs bcw lec -> boost chaos bludgeonia
dcs bcw mic -> boost chaos swordia
dcs bcw grm -> boost chaos axe

dcs cpl lec -> returnaa warlock guildaan
dcs cpl mic -> returnaa cs
dcs cpl grm -> returnaa playerin start locationiin

dcs cab lec -> hp|sp|ep boost demonille
dcs cab mic -> stat boost demonille
dcs cab grm -> skillstarttaus chance boost demonil

dcs bcw lec -> boostaa chaos bludia
bless chaos bludgeon
This spell is used to bless the chaos bludgeon.
dcs bcw mic -> boostaa chaos swordia
dcs bcw grm -> boostaa chaos axea

life link -> demon kayttaa sun hpeita, master ottaa % damaa jos demon ottaa iskua
Demon XP RANKS
child of chaos
chaos incarnate
prince of chaos
prophet of chaos
hellraiser
chaos|shadow bane


Initiate of the 1st Circle
Initiate of the 2nd Circle
Initiate of the 3rd Circle
Initiate of the 4th Circle
Initiate of the 5th Circle

Warlock Prince
Grand Warlock

Warlock weapon ?
Chaos Blade

Guilds

Demons ???
Scavenger
switch(WARLOCK_D->query_demon_xp(this_player()->query_real_name())) {
case 0..5000000: str = "Initiate of the Third Circle"; break;
case 5000001..10000000: str = "Member of the Third Circle"; break;
case 10000001..20000000: str = "Adept of the third Circle"; break;
case 20000001..50000000: str = "Master of the Third Circle"; break;
case 50000001..75000000: str = "Candidate of the Second Circle"; break;
case 75000001..100000000: str = "Member of the Second Circle"; break;
case 100000001..175000000: str = "Elder of the Second Circle"; break;
case 175000001..300000000: str = "Ruler of the Second Circle"; break;
case 300000001..500000000: str = "Servant of the First Circle"; break;
case 500000001..750000000: str = "Follower of the First Circle"; break;
case 750000001..900000000: str = "Member of the First Circle"; break;
case 900000001..999999999: str = "Elder of the First Circle"; break;
case 1000000000: str = "Overlord of the Warlocks"; break;
}
*/