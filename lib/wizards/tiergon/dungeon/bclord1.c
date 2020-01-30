inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {
   if (!monster) {
   monster = clone_object("/wizards/tiergon/dungeon/monsters/bcfighter2"); 
   move_object(monster, this_object()); }
   if (arg) return;     
set_not_out(3);
set_door_dir("south","/wizards/tiergon/dungeon/b10");
set_door_link("/wizards/tiergon/dungeon/b10");
random_door_code();
set_door_desc("iron ");
add_exit("north","/wizards/tiergon/dungeon/bclord2");
add_exit("east","/wizards/tiergon/dungeon/bclord3");
  short_desc = "A surprisingly cosy waiting room";
  long_desc = "The walls of this room have been tastefully paneled with a variety of exotic woods.\n"+ 
              "A fire burns merrily in the corner.\n";
}
init() {
  ::init();
  door_init();
}
