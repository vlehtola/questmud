#define CMD_D "/wizards/rimber/test/dragon_cmd.c"
#define SAVE_FILE "/wizards/rimber/test/dragon_test"
#define SPESSUT "/wizards/rimber/test/dragon_hits"

inherit "obj/monster";
static string master, short, type;
int follow_mode = 0;
string what;
string target;
mapping drage_xp;


 // DRAGON TYPE
void setType(string tmp) { type = tmp; }

 // Maaritellaan masteri    
string masteri() {
 master = "/wizards/rimber/test/room2.c"->master();
 tell_room(environment(this_player()), "Dragon booms: 'You called Master "
 +master+"?\n");
 short = master + "s";
 this_object()->setAlias(short);
 return master;
}

query_controller() {
 return master;
}

query_hunter_list() { return 0; }

short() { return short; }


long() { write("This is "+master+"'s pet dragon. Dragonmaster's usually command these beasts\n"+
 "simply saying what the beast must to do.\nWord 'help' will give you more instructions.\n");
}

 // Dragon's stats
query_str() {
 int lvl = this_object()->query_level();
 int tmp = "/wizards/rimber/test/testi.c"->GetStats(lvl, type, "str");
 return tmp;
}
query_con() {
 int lvl = this_object()->query_level();
 int tmp = "/wizards/rimber/test/testi.c"->GetStats(lvl, type, "con");
 return tmp;
}
query_dex() {
 int lvl = this_object()->query_level();
 int tmp = "/wizards/rimber/test/testi.c"->GetStats(lvl, type, "dex");
 return tmp;
}
query_wis() {
 int lvl = this_object()->query_level();
 int tmp = "/wizards/rimber/test/testi.c"->GetStats(lvl, type, "wis");
 return tmp;
}
query_int() {
 int lvl = this_object()->query_level();
 int tmp = "/wizards/rimber/test/testi.c"->GetStats(lvl, type, "int");
 return tmp;
}
query_max_hp() {
 return (this_object()->query_con() * 7);
}
query_max_sp() {
 return (this_object()->query_int() * 6 + this_object()->query_wis() * 4);
}
query_max_ep() {
 return (this_object()->query_con());
}
query_money() { return 0; }

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_level(1);
  set_hp(query_max_hp());
  set_sp(query_max_sp());
  set_ep(query_max_ep());
 set_exp(1);
 set_extra(1);
 set_name("dragon");
 set_alias("dragon");

 set_dead_ob(this_object());
 call_out("regeni", 5);
}


  // SPESSU??
extra() {
 if(random(201) < 130) return 1;
 if(random(201) < 140) { SPESSUT->claw_scratch(this_object()); return 1; }
 if(random(210) < (100+this_object()->query_attacker()->query_level())) { SPESSUT->fire_breath(this_object()); return 1; }
 SPESSUT->fire_blast(this_object());
 return 1;
}
get() { return 0; }  // Ei mahu taskuun

init() {
 add_action("dragon", "dragon");
}

status dragon(string str) {
 if(!str) { write("Use 'dragon help' to see commands.\n");
  return 1;
 }
CMD_D->cmd_dragon(str);
  CMD_D->cmd_d(this_object());
 return 1;
}

catch_tell(str) {
 string who, what, dir;
 object kuka;   
 if(sscanf(str, "%s leaves %s.", who, dir) == 2) {
 kuka = find_player(lower_case(who));
 if(!kuka) { return 1; }
  if(follow_mode == 0) { return 1; }
 if(who != master) { return 1; }
 init_command(dir);
 }
 if(sscanf(str, "%s is in vigorous combat with %s.", who, what) == 2) {
 if(!this_object()->query_attacker()) { return 1; }
 if(lower_case(who) == lower_case(master)) {
 if(lower_case(what) == lower_case(master)) return 1;
 object ob = present(lower_case(what), environment(this_object()));
 if(find_player(ob)) { return 1; }
 this_object()->attack_object(ob);
   }
 }
}

void setFollowMode(int tmp) { follow_mode = tmp; }
void setAlias(string tmp) {
 int lvl = this_object()->query_level();
 string tmp2;
 switch(lvl) {
  case 1..20 : tmp2 = "the small";
  case 21..40 : tmp2 = "the";
  case 41..60 : tmp2 = "the large";
  case 61..80 : tmp2 = "the enormous";
 }
 short = tmp + " " + tmp2 + " " + type + " dragon";
 }

regeni() {
 if(!attacker_ob) {
  int hp = this_object()->query_hp();
  hp = hp + (this_object()->query_max_hp() / 100 * 5);
  if(hp > this_object()->query_max_hp()) hp = this_object()->query_max_hp();
  set_hp(hp);
 }
 call_out("regeni", 50);
 return 1;
}

