inherit "room/room";

reset(arg) {
set_not_out(3);
add_exit("east","/wizards/tiergon/dungeon/b10");
add_exit("south","/wizards/tiergon/dungeon/b6");
  short_desc = "The northern aisle";
  long_desc = "The northern aisle is quite similar to the main one, for the exception of the pews covering the north wall.\n";
items = allocate (2);
items[0] = "pews";
items[1] = "The pews have been made from black wood and show avatars of Morai raping women and performing other such actions befitting the Betrayer"; }
