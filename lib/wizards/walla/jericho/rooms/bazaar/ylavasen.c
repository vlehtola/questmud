inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/map");
   return 1;
}
object monster,kartti;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/reg");
    move_object(monster, this_object());
  }
 
  if(!kartti) {
    kartti = clone_object("/wizards/walla/jericho/stuph/cart1");
    move_object(kartti, this_object());
  }

  if(arg) return;
  add_exit("west","wizards/walla/jericho/rooms/bazaar/wentrance");
  add_exit("east","wizards/walla/jericho/rooms/bazaar/ylakeski");
  add_exit("north","wizards/walla/jericho/rooms/bazaar/nentrance");
  short_desc = "In the bazaar";
  long_desc =
"You are standing at the in the northwestern corner of the bazaar.\n" +
"There is a shopping cart here, that is owned by Reg Rubseh.\n" +
"Reg is one of the more prosperous salesmen here, and therefore he has\n" +
"been allowed to choose the best location for his goods and merchandises.\n" +
"\n";
 
}

