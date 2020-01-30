#define SAVE_FILE "/data/demon_xp"
#define STACK_D "/daemons/string_stack_d"
#define SKILLFUN "/guilds/obj/skillfun"
#define MAX_XP 1000000000
#define MAX_SOULS 10000000
mapping demon_xp;
mapping souls;
string *tasks;
static invite;
static is_demon;
static string * rem_say(string arg,string * arr);
static status last_say(string *arr);
query_max_xp() { return 1000000000; }
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
do_eat(string str, object who) {
object ob;
if(!who)return;
if(!str) {
do_say("What should i eat?", who);
return 1;
}
ob = present(str, who);
if(!ob) {
do_say("I don't have such thing.", who);
return 1;
}
if(!ob->query_corpse()) {
do_say("I can only eat fresh corpses.", who);
return 1;
}
tell_room(environment(who), who->query_name()+" eats "+ob->short()+".\n", ({ who }));
who->set_food(ob->query_level()+50);
destruct(ob);
do_say("That tasted very good!", who);
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
    do_say("Go to hell.\n",who);
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
  do_say("I can't use skills in here.",who);
  return 1;
}
if(who->query_ep() < 1) {
  do_say("I don't have enough endurance points.", who);
  return 1;
}

if (!str) {
 do_say("What skill should i use?",who);
 return 1;
}

if (str == "stop") {
  if (skill) {
   do_say("I stopped my skill attempt.",who);
    skill->interrupt_skill();
    return 1;
    } else {
      do_say("I am not doing anything.",who);
      return 1;
    }
  }
  if (skill) {
    do_say("Ok iam starting new skill.", who);
    destruct(skill);
  }
  if (spell) {
    do_say("I stopped my spellcasting.",who);
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
  tasks = ({ });
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

add_demon_xp(string str, int i) {
	demon_xp[str] += i;
	save_object(SAVE_FILE);
}
add_souls(string str, int i) {
if(souls[str] > MAX_SOULS)return;
souls[str] += i;
save_object(SAVE_FILE);
}

reduce_souls(string str, int i) {
int x;
int t;
t = (this_player()->query_skills("soul channeling")+100)/2;
x = i/2;
x = (x * 100) / t;
i = i-x;
write("You saved "+x+" souls because of your superior knowledge in soul channeling.\n");
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
summon_demon(string str, int power, string type) {
int chance;
int plus;
chance=this_player()->query_skills("knowledge of summoning")/5;
chance+=this_player()->query_skills("demonology")/5;

if(str == "minor" &&  query_demon_xp(this_player()->query_real_name()) < 110000000) {
write("A somekind of hollow dark voice says in your head: You can't call that kind of demons just yet!\n");
return 1;
}
if(str == "greater" &&  query_demon_xp(this_player()->query_real_name()) < 360000000) {
write("A somekind of hollow dark voice says in your head: You can't call that kind of demons just yet!\n");
}
if(query_demon(this_player()->query_real_name())) {
	write("You already have demon.\n");
	return 1;
}
if(environment(this_player())->query_summon_circle()) {
write("This place makes the summoning much easier.\n");
plus=50;
}
if(present("circle_of_chaos", environment(this_player()))) {
write("The circle glows as you start summoning the demon.\n");
plus+=50;
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
get_demon(str, type, chance);
if(power) {
write("You spend some of the souls to boost the summoning.\n");
}
}
/* demons?
punisher | executioner |
*/
get_short(string str) {
int i, pexp, mexp;

pexp = query_demon_xp(this_player()->query_real_name()) / 100000;
mexp = 1000000000 / 100000;
i = (pexp * 100) / mexp;
if(this_player()->query_wiz()) {
write("Your current demonxp :"+i+"% from max\n");
}
switch(i) {
case 0..1: return "Scavenger Demon";
case 2..3: return "Punisher Demon";
case 4..6: return "Executioner Demon";
case 7..10: return "Spawn Demon";
case 11..15: return "Blood Demon";
case 16..20: return "Torturer Demon";
case 21..25: return "Spike Demon";
case 26..35: return "Horn Demon";
case 36..50: return "Wicked Demon";
case 51..75: return "Reaver Demon";
case 76..90: return "Chaos Demon";
case 91..99: return "Demon Lord";
case 100: return "Arch-Demon";
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
case "Blood Demon":
return "This is the Blood Demon, smallest and weakest demon of Second Circle. But "+
"infact it's not so weak, it could single handedly kill all demons of Third Circle. "+
"The name 'Blood demon' comes from it's color. And maybe the way it's born affects  "+
"the name. These demons are born, or actually made from pool of blood. It requires "+
"lot of blood, as you can conclude from it's size, it's HUGE! The blood in the pool "+
"is from paladins, that's the best way to humiliate the main enemies of warlocks. "+
"These demons also need to have fresh blood to keep their form and strength. As it "+
"walks it leaves bloody footprints and drips blood everywhere. Also the victims of "+
"these demons are easily identified, because they are all over bloody, but their "+
"veins got nothing inside.";
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
get_stats(string str, object ob) {
int tmp;
int dxp;
tmp = 0;
dxp = 0;
switch(query_demon_xp(this_player()->query_real_name())) {
case 0..5000000: dxp = 10; break;
case 5000001..10000000: dxp = 20; break;
case 10000001..20000000: dxp = 30;  break;
case 20000001..50000000: dxp = 40;  break;
case 50000001..75000000: dxp = 50; break;
case 75000001..100000000: dxp = 60; break;
case 100000001..175000000: dxp = 70; break;
case 175000001..300000000: dxp = 80; break;
case 300000001..500000000: dxp = 90; break;
case 500000001..750000000: dxp = 100; break;
case 750000001..900000000: dxp = 110; break;
case 900000001..999999999: dxp = 120; break;
case 1000000000: dxp = 150; break;
}

switch(str) {
case "str":
tmp = this_player()->query_skills("knowledge of fighter")/8+10;
tmp = (tmp + ob->query_level())*4;
tmp = tmp+random(random(tmp));
tmp = tmp/4;
return tmp+dxp;
break;
case "dex":
tmp = this_player()->query_skills("knowledge of fighter")/8+10;
tmp = (tmp + ob->query_level())*4;
tmp = tmp+random(random(tmp));
tmp = tmp/4;
return tmp+dxp;
break;
case "con":
tmp = ob->query_level()+ob->query_size()+ob->query_str();
tmp = tmp+random(tmp)*2;
return tmp/2+dxp;
break;
case "int":
tmp = this_player()->query_skills("knowledge of mage")/8+10;
tmp = (tmp + ob->query_level())*4;
tmp = tmp+random(random(tmp));
tmp = tmp/4;
return tmp+dxp;
break;
case "wis":
tmp = this_player()->query_skills("knowledge of cleric")/8+10;
tmp = (tmp + ob->query_level())*4;
tmp = tmp+random(random(tmp));
tmp = tmp/4;
return tmp+dxp;
break;
case "hp": return (ob->query_con()+ob->query_level()+ob->query_size()+dxp*2)*2;
case "sp": return (ob->query_int()+ob->query_level()+ob->query_wis()+dxp*2)*2;
case "ep": return (ob->query_con()+ob->query_level()+ob->query_str()+dxp*2);
}
return 1;
}

get_demon(string str, string type, boost) {
object demon;
int skillmax;
demon = clone_object("/guilds/warlock/obj/demon");
move_object(demon, environment(this_player()));
demon->set_name("demon");
demon->set_short("A "+str+" "+get_short(str));
demon->set_long(get_long(get_short(str))+".\nIt is a demon.\n");
demon->no_money();
demon->set_level(get_level(str, get_short(str)));
demon->set_random_pick(0);
demon->set_str(get_stats("str", demon)+random(50));
demon->set_dex(get_stats("dex", demon)+random(50));
demon->set_con(get_stats("con", demon)+random(50));
demon->set_int(get_stats("int", demon)+random(50));
demon->set_wis(get_stats("wis", demon)+random(50));
demon->set_al(-100);
demon->set_al_aggr(200);
demon->set_controller(this_player()->query_real_name());
add_demon(this_player()->query_real_name(), demon);
demon->set_max_hp(get_stats("hp", demon));
demon->set_max_sp(get_stats("sp", demon));
demon->set_max_ep(get_stats("ep", demon));
demon->set_hp(demon->query_max_hp());
demon->set_ep(demon->query_max_ep());
demon->set_sp(demon->query_max_sp());
if(demon->query_max_hp() > 3000) {
demon->set_max_hp(3000);
demon->set_hp(3000);
}
if(demon->query_max_sp() > 5000) {
demon->set_max_sp(5000);
demon->set_sp(5000);
}
if(demon->query_max_ep() > 1000) {
demon->set_max_ep(1000);
demon->set_ep(1000);
}

if(type == "cleric") {
skillmax = demon->query_level()*4+this_player()->query_skills("knowledge of chaos")+this_player()->query_skills("knowledge of cleric");
demon->set_skills("cast heal", skillmax / SKILLFUN->skill_cost("cast heal")+10);
demon->set_skills("cast divine", skillmax / SKILLFUN->skill_cost("cast divine")+10);
demon->set_skills("cast satisfy",  skillmax / SKILLFUN->skill_cost("cast satisfy")+10);
demon->set_skills("cast transfer",  skillmax / SKILLFUN->skill_cost("cast transfer")+10);
demon->set_skills("cast cure",  skillmax / SKILLFUN->skill_cost("cast cure")+10);
demon->set_skills("cast bless",  skillmax / SKILLFUN->skill_cost("cast bless")+10);
demon->set_skills("cast holy alteration",  skillmax / SKILLFUN->skill_cost("cast holy alteration")+10);
demon->set_skills("chanting",  skillmax / SKILLFUN->skill_cost("chanting")+10);
demon->set_skills("channel",  skillmax / SKILLFUN->skill_cost("channel")+10);
demon->set_skills("master of medicine",  skillmax / SKILLFUN->skill_cost("mastery of medicine")+10);
demon->set_skills("cast major",  skillmax / SKILLFUN->skill_cost("cast major")+10);
demon->set_skills("cast lesser",  skillmax / SKILLFUN->skill_cost("cast lesser")+10);
demon->set_skills("cast minor",  skillmax / SKILLFUN->skill_cost("cast minor")+10);
demon->set_wis(demon->query_wis()+150);
demon->set_max_sp(demon->query_max_sp()+1000);
demon->set_sp(demon->query_max_sp());

}
if(type == "fighter") {
skillmax = demon->query_level()*4+this_player()->query_skills("knowledge of chaos")+this_player()->query_skills("knowledge of fighter");
demon->set_skills("strike", skillmax / SKILLFUN->skill_cost("strike"));
demon->set_skills("critical", skillmax / SKILLFUN->skill_cost("critical"));
demon->set_skills("bludgeons", skillmax / SKILLFUN->skill_cost("bludgeons"));
demon->set_skills("axes", skillmax / SKILLFUN->skill_cost("axes"));
demon->set_skills("blades", skillmax / SKILLFUN->skill_cost("blades"));
demon->set_skills("pound", skillmax / SKILLFUN->skill_cost("pound"));
demon->set_skills("slash", skillmax / SKILLFUN->skill_cost("slash"));
demon->set_skills("cut", skillmax / SKILLFUN->skill_cost("cut"));
demon->set_skills("dodge", skillmax / SKILLFUN->skill_cost("dodge"));
demon->set_skills("parry", skillmax / SKILLFUN->skill_cost("parry"));
demon->set_skills("foresee attack", skillmax / SKILLFUN->skill_cost("foresee attack"));
demon->set_skills("stun", skillmax / SKILLFUN->skill_cost("stun"));
demon->set_skills("inner strength",skillmax / SKILLFUN->skill_cost("inner strength"));
demon->set_skills("two weapons combat", skillmax / SKILLFUN->skill_cost("two weapons combat"));
demon->set_skills("stunned maneuvers", skillmax / SKILLFUN->skill_cost("stunned maneuvers"));
demon->set_skills("weapon parry", skillmax / SKILLFUN->skill_cost("weapon parry"));
demon->set_skills("shield parry", skillmax / SKILLFUN->skill_cost("shield parry"));
demon->set_skills("find weakness", skillmax / SKILLFUN->skill_cost("find weakness"));
demon->set_skills("agility",skillmax / SKILLFUN->skill_cost("agility"));
demon->set_skills("ignore wrong strike", skillmax / SKILLFUN->skill_cost("ignore wrong strike"));
demon->set_skills("deceived attack", skillmax / SKILLFUN->skill_cost("deceived attack"));
demon->set_skills("throw weight",skillmax / SKILLFUN->skill_cost("throw weight"));
demon->set_skills("shield bash", skillmax / SKILLFUN->skill_cost("shield bash"));
demon->set_skills("first strike", skillmax / SKILLFUN->skill_cost("first strike"));
demon->set_skills("endurance",skillmax / SKILLFUN->skill_cost("endurance"));
demon->set_str(demon->query_str()+30);
demon->set_max_hp(demon->query_max_hp()+300);
demon->set_hp(demon->query_max_hp());

}
if(type == "mage") {
skillmax = demon->query_level()*4+this_player()->query_skills("knowledge of chaos")+this_player()->query_skills("knowledge of mage");
demon->set_skills("cast earth", skillmax / SKILLFUN->skill_cost("cast earth"));
demon->set_skills("cast fire", skillmax / SKILLFUN->skill_cost("cast fire"));
demon->set_skills("cast ice", skillmax / SKILLFUN->skill_cost("cast ice"));
demon->set_skills("cast electric", skillmax / SKILLFUN->skill_cost("cast electric"));
demon->set_skills("cast essence", skillmax / SKILLFUN->skill_cost("cast essence"));
demon->set_skills("cast create", skillmax / SKILLFUN->skill_cost("cast create"));
demon->set_skills("cast bolt", skillmax / SKILLFUN->skill_cost("cast bolt"));
demon->set_skills("cast trade", skillmax / SKILLFUN->skill_cost("cast trade"));
demon->set_skills("cast information", skillmax / SKILLFUN->skill_cost("cast information"));
demon->set_skills("cast storm", skillmax / SKILLFUN->skill_cost("cast storm"));
demon->set_skills("cast force field", skillmax / SKILLFUN->skill_cost("cast force field"));
demon->set_skills("cast teleport", skillmax / SKILLFUN->skill_cost("cast teleport"));
demon->set_skills("cast locate", skillmax / SKILLFUN->skill_cost("cast locate"));
demon->set_skills("power channeling", skillmax / SKILLFUN->skill_cost("power channeling"));
demon->set_skills("power concentration", skillmax / SKILLFUN->skill_cost("power concentration"));
demon->set_skills("power focusing", skillmax / SKILLFUN->skill_cost("power focusing"));
demon->set_skills("mana control", skillmax / SKILLFUN->skill_cost("mana control"));
demon->set_skills("chanting", skillmax / SKILLFUN->skill_cost("chanting"));
demon->set_skills("mastery of commerce", skillmax / SKILLFUN->skill_cost("mastery of commerce"));
demon->set_skills("evaluate", skillmax / SKILLFUN->skill_cost("evaluate"));
demon->set_skills("bargain", skillmax / SKILLFUN->skill_cost("bargain"));
demon->set_skills("proximity blast", skillmax / SKILLFUN->skill_cost("proximity blast"));
demon->set_skills("stunning blast", skillmax / SKILLFUN->skill_cost("stunning blast"));
demon->set_skills("distract concentration", skillmax / SKILLFUN->skill_cost("distract concentration"));
demon->set_skills("lore of cold", skillmax / SKILLFUN->skill_cost("lore of cold"));
demon->set_skills("knowledge of heat", skillmax / SKILLFUN->skill_cost("knowledge of heat"));
demon->set_skills("theory of electricity", skillmax / SKILLFUN->skill_cost("theory of electricity"));
demon->set_skills("invoke ethereal mana", skillmax / SKILLFUN->skill_cost("invoke ethereal mana"));
demon->set_skills("elusive spellcasting", skillmax / SKILLFUN->skill_cost("elusive spellcasting"));
demon->set_skills("reflect spell", skillmax / SKILLFUN->skill_cost("reflect spell"));
demon->set_skills("cast illusion", skillmax / SKILLFUN->skill_cost("cast illusion"));
demon->set_skills("counter spell", skillmax / SKILLFUN->skill_cost("counter spell"));
demon->set_skills("navigation mastery", skillmax / SKILLFUN->skill_cost("navigation mastery"));
demon->set_int(demon->query_int()+50);
demon->set_max_sp(demon->query_max_sp()+1000);
demon->set_sp(demon->query_max_sp());
}
skillmax = demon->query_level()*4+this_player()->query_skills("knowledge of chaos");
demon->set_skills("chaos strike", skillmax / SKILLFUN->skill_cost("chaos strike")+10);
demon->set_skills("kick", skillmax / SKILLFUN->skill_cost("kick")+10);
demon->set_skills("torch creation", skillmax / SKILLFUN->skill_cost("torch creation")+10);
demon->set_skills("hunting", skillmax / SKILLFUN->skill_cost("hunting")+10);
demon->set_skills("fire building", skillmax / SKILLFUN->skill_cost("fire building")+10);
demon->set_skills("punch", skillmax / SKILLFUN->skill_cost("punch")+10);
demon->set_skills("bare hands", skillmax / SKILLFUN->skill_cost("bare hands")+10);
demon->set_skills("chaos bludgeons", skillmax / SKILLFUN->skill_cost("chaos bludgeons")+10);
demon->set_skills("chaos blades", skillmax / SKILLFUN->skill_cost("chaos blades")+10);
demon->set_skills("chaos axes", skillmax / SKILLFUN->skill_cost("chaos axes")+10);
demon->set_skills("attack", skillmax / SKILLFUN->skill_cost("attack")+10);
demon->set_skills("doublehit", skillmax / SKILLFUN->skill_cost("doublehit")+10);
demon->set_skills("cast plane of chaos", skillmax / SKILLFUN->skill_cost("cast plane of chaos")+10);
demon->set_skills("cast forge of chaos", skillmax / SKILLFUN->skill_cost("cast forge of chaos")+10);
demon->set_skills("cast anvil of chaos", skillmax / SKILLFUN->skill_cost("cast anvil of chaos")+10);
demon->set_skills("cast blessing of chaos", skillmax / SKILLFUN->skill_cost("cast blessing of chaos")+10);
demon->set_skills("cast void travel", skillmax / SKILLFUN->skill_cost("cast void travel")+10);
demon->set_skills("essence of chaos", skillmax / SKILLFUN->skill_cost("essence of chaos")+10);
demon->set_skills("cast lesser chaos", skillmax / SKILLFUN->skill_cost("cast lesser chaos")+10);
demon->set_skills("cast minor chaos", skillmax / SKILLFUN->skill_cost("cast minor chaos")+10);
demon->set_skills("cast greater chaos", skillmax / SKILLFUN->skill_cost("cast greater chaos")+10);
demon->set_epreg(demon->query_max_ep()/8+10);
demon->set_spreg(demon->query_max_sp()/4+50);
demon->set_hpreg(demon->query_max_hp()/12+30);

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
(["siki":918554,"devil":25455,"koff":61876,"cyborn":33997,"cathoris":30583,"cre
mater":3088,"sikitest":9978950,15:0,])
Demons ???
Scavenger
switch(WARLOCK_D->query_demon_xp(this_player()->query_real_name())) {
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
*/
