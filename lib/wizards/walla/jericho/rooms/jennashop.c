inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/ujar1");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/jenna");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/walla/jericho/rooms/ujar1");
  short_desc = "The alchemists shop";
  long_desc =
"The alchemist's shop has surely run down much more that you would\n" +
"have expected. It is now, only a small hut, with a counter. Potions\n" +
"are stacked along the walls, and nowadays the shop also sells medications.\n" +
"After Efraim died, her daughter has taken over the shop.\n";
 
}
