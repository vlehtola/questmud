inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {
   if (!monster) {
   monster = clone_object("/wizards/tiergon/dungeon/monsters/bcamazonian");
   move_object(monster, this_object()); }
   if (arg) return;     
set_not_out(3);
set_door_dir("north","/wizards/tiergon/dungeon/bclord1");
set_door_link("/wizards/tiergon/dungeon/bclord1");
random_door_code();
set_door_desc("iron ");
add_exit("east","/wizards/tiergon/dungeon/b10");
add_exit("south","/wizards/tiergon/dungeon/b5");
add_exit("west","/wizards/tiergon/dungeon/b12");
  short_desc = "The northern aisle";
  long_desc = "The northern aisle is quite similar to the main one, for the exception of the"+ 
              " pews covering the north wall.\n";
items = allocate(4);
items[0] = "pews";
items[1] = "The pews have been made from black wood and show avatars of Morai raping women and performing other such actions befitting the Betrayer"; }

init() {
  ::init();
  door_init();
}
