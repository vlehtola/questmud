inherit "room/room";
reset(arg) {
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/c8");
add_exit("east","/wizards/tiergon/dungeon/c4");
add_exit("south","/wizards/tiergon/dungeon/c9");
add_exit("west","/wizards/tiergon/dungeon/c2");
  short_desc = "A new tunnel";
  long_desc = "The tunnel slopes smoothly downwards.\n"+
                "The walls are supernaturally smooth and look like they have been recently finished. They were probably made by the Black Circle wizards.\n"; }

