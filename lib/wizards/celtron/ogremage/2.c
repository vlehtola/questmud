inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc = "A room with a fireplace";
  long_desc =
"A strong and fierce smell of sweat and beer surrounds you.\n"+
"The walls are made of huge tree trunks and there is no floor at all.\n"+
"The ceiling has blackened from the smoke coming from the broken chimney.\n"+
"A fire in the fireplace throws shadows on the opposite wall.\n"+
"There is a table in the middle of the room.\n";
  items = allocate(4);
  items[0] = "table";
  items[1] =
"The table is made of harsh wood and doesn't look very balanced.\n"+
"A parchament is left on the table, it seems to be somekind of a plan.\n";
  items[2] = "plan";
  items[3] =
"You manage to examine the plan with a quick glance; there are some arrows\n"+
"and houses drawn. There is also some text on the plan: 'Duranghom'.\n"+
"You might be able to grab the plan and run warn the city guards.\n";

  move_object(clone_object("/wizards/celtron/ogremage/giant_leader"), this_object());
  move_object(clone_object("/wizards/celtron/ogremage/ogre_mage"), this_object());
  add_exit("north", "/wizards/celtron/ogremage/1");
}

ogre_wimpy() {
  add_exit("west", "/wizards/celtron/ogremage/3");
  move_object(clone_object("/wizards/celtron/ogremage/big_guard"), this_object());
  move_object(clone_object("/wizards/celtron/ogremage/big_guard"), this_object());
  move_object(clone_object("/wizards/celtron/ogremage/big_guard"), this_object());
  tell_room(this_object(), "Guards arrive from the north.\n");
}

init() {
  add_action("take_map", "grab");
}

take_map(string str) {
  object ob,ob2;
  if(str == "plan") return 0;
  write("You grab the plan from the table.\n");
  say(this_player()->query_name()+" grabs the plan from the table.\n");
  ob = present("heinr");
  ob2 = present("grumph");
  if(ob) {
    tell_room(this_object(), "Heinr shouts 'HEY! You are not taking our plan! GUARDS!'\n");
    ob->attack_object(this_player());
  }
  if(ob2) {
    tell_room(this_object(), "Grumph states 'You are dead meat.'\n");
    ob2->turn_invisible();
    ob2->attack_object(this_player());
  }
  move_object(clone_object("/wizards/celtron/ogremage/plan"), this_player());
  move_object(clone_object("/wizards/celtron/ogremage/small_guard"), this_object());
  return 1;
}
