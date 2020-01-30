status cannot_take;
status used;

get_weapon(string str) {
  object ob;
  string tmp;
  if(str != "sword" && str != "axe" && str != "mace") return 0;
  if(cannot_take) {
    write("The rack is empty..wait for a while.\n");
    return 1;
  }
  ob = clone_object("/world/objects/rack_weapon");
  ob->set_rack_type(str);
  move_object(ob, this_player());
  tmp = "a";
  if(str == "axe") tmp = "an";
  write("You take "+tmp+" "+str+" from the rack.\n");
  say(this_player()->query_name()+" takes "+tmp+" "+str+" from the rack.\n");
  cannot_take = 1;
  call_out("can_take", 300);
  return 1;
}

can_take() {
  cannot_take = 0;
  tell_room(environment(this_object()), "A weapon emerges to the rack.\n");
}

init() {
  add_action("get_weapon", "take");
}

short() { return "A wooden rack containing weapons"; }
long() {  write(
"The rack is made of raw planks. All kinds of weapons are attached to it;\n"+
"swords, maces and axes. You can take these weapons for they are for the\n"+
"guild's members. (ie. 'take sword')\n");
}
id(str) { return str == "rack"; }
