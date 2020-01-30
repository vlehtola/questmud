inherit "room/room";
object monster;

reset(arg) {
   if (!monster) {
   monster = clone_object("/wizards/tiergon/dungeon/monsters/bcacolyte");
   move_object(monster, this_object()); }
set_not_out(3);
add_exit("north","/wizards/tiergon/dungeon/b8");
add_exit("east","/wizards/tiergon/dungeon/b3");
add_exit("south","/wizards/tiergon/dungeon/b9");
add_exit("west","/wizards/tiergon/dungeon/b5");
  short_desc = "The central aisle";
  long_desc = "The central aisle of the chapel is an impressive corridor made from black veined marble.\n"+
                "The room is lit by a magical light from the roof.\n";
}
