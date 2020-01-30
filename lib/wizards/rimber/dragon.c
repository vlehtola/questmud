string master, short;
int follow_mode;

reset(arg) {
 if(arg) return;
 follow_mode = 0;
}

string masteri() {
 master = "/wizards/rimber/test/room2.c"->master();
 tell_room(environment(this_player()), "Dragon booms: 'You called Master "+master+"?\n");
 short = master+"'s pet dragon";
 return master;
}  

short() { return short; }

id() { return "dragon"; }

long() { write("This is "+master+"'s pet dragon. Dragonmaster's usually command these beasts\n"+
 "simply saying what the beast must to do.\nWord 'help' will give you more instructions.\n");
}


init() {
 add_action("dragon", "dragon");
}

status dragon(string str) {
 object ob;
 string what;
 if(!str) { write("Use 'dragon help' to see commands.\n");
  return 1;
 }
 if(sscanf(str, "attack %s", what) == 1) {
  ob = find_object(what);
  if(!ob) {
   tell_room(environment(this_player()), "Dragon booms: 'Who you want me to kill Master?'\n");
   return 1;
  }
  tell_room(environment(this_player()), "Dragon booms: 'As you wish Master.'\n");
  return 1;
 }
 if(str == "help") {
  write("Dragon's commands:\n 'follow' Makes dragon to follow "+
 "you.\n 'stay' makes it stop following.\n 'eat corpse' Dragon eats corpse.\n "+
 "'attack <target>' Makes dragon to attack given target.\n 'dismiss' The dragon "+
 "leaves.\n\n");
  return 1;
 }
 if(str == "follow") {
  tell_room(environment(this_player()), "Dragon booms: 'I will now follow you Master.'\n");
  follow_mode = 1;
  return 1;
 }
 if(str == "dismiss") {
 ob = this_object();
 tell_room(environment(this_player()), "Dragon booms: 'If that's your command Master.\n");
 tell_room(environment(this_player()), "Dragon disappears.\n");
 destruct(ob);
 return 1;
 }
 return 1;
}

catch_tell(fol) {
 string who, dir;
 object kuka;
 if(sscanf(fol, "%s leaves %s.", who, dir) == 2) {
 kuka = find_player(lower_case(who));
 if(!kuka) return;
  if(follow_mode == 0) return;
  if(who != master) return;
  init_command(dir);
 return 1;
 }
 return 1;
}
