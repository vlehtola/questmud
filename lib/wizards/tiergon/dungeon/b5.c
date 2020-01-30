inherit "room/room";
object monster;

reset(arg) {
set_not_out(3);
add_exit("north","/wizards/tiergon/dungeon/b10");
add_exit("east","/wizards/tiergon/dungeon/b4");
add_exit("south","/wizards/tiergon/dungeon/b11");
add_exit("west","/wizards/tiergon/dungeon/b6");
  short_desc = "The central aisle";
  long_desc = "The central aisle of the chapel is an impressive corridor made from black veined marble.\n"+
                "The room is lit by a magical light from the roof.\n";
}
