string name;

reset(arg) {
    if (arg) { return; }
    name = "machine";
}

set_name(n) { name = n; }

short() { return "A free equipment dispenser machine"; }

long() {
  write("Old, rusty machine stands about 2 metres tall. There's a red button on it\n");
  write("labelled 'Push me!'. Rotten wooden plaque, including VERY long instrutions\n"); 
  write("about the use of this fantastic machine, hangs from a nail. Too bad that the\n");
  write("plaque is in unreadable condition...it might contain some useful information.\n");
}

get() { return 0; }

init() {
  add_action("dispense", "push");
}

dispense(str) {
  string st;
  object ob, ob2;
  st = str;
  if (st == "button") {
    ob = clone_object("world/eq/weapons/object");
    move_object(ob, this_player());
    ob2 = clone_object("world/eq/armours/newarmo");
    move_object(ob2, this_player());
    this_player()->fix_weight();
    write("Nothing seems to happen.. but suddenly something heavy drops noisily on your\n");
    write("feet causing static pain! You'll pick them up and are happy, because things\n");
    write("could be a lot worse.\n");
    this_player()->set_hp(this_player()->query_hp() - 20);
    return 1;
  }
  else {
    write("'Push button', perhaps?\n");
    return 1;
  }
}

id(str) {
    return str == name;
}
