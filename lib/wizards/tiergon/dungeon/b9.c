inherit "room/room";

reset(arg) {

set_not_out(3);
add_exit("north","/wizards/tiergon/dungeon/b4");
add_exit("west","/wizards/tiergon/dungeon/b11");
  short_desc = "The southern aisle";
  long_desc = "The southern aisle is quite similar to the main one, for the exception of the pews covering the south wall.\n";
items = allocate (2);
items[0] = "pews";
items[1] = "The pews have been made from black wood and show avatars of Morai raping women and performing other such actions befitting the Betrayer"; }
