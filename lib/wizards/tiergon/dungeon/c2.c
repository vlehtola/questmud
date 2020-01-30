inherit "room/room";
reset(arg) {
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/c6");
add_exit("east","/wizards/tiergon/dungeon/c3");
add_exit("south","/wizards/tiergon/dungeon/c7");
add_exit("west","/wizards/tiergon/dungeon/c1");
  short_desc = "A new tunnel";
  long_desc = "The tunnel slopes smoothly downwards.\n"+
                "The walls are supernaturally smooth and look like they have been recently finished. They were probably made by the Black Circle wizards\n"; }

