inherit "room/room";
init() {
   ::init();
   add_action("map", "map");
}
 
map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/htuos-1");
   return 1;
}
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/jericho/mobs/cit1");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/walla/jericho/rooms/htuos-2");
  add_exit("east","wizards/walla/jericho/rooms/ujar5");
  short_desc = "On Htuos street";
  long_desc =
"You area standing on Htuos street, which is one of the main roads of Jericho.\n" +
"This road follows the southern citywall, and is partly shrouded by it.\n" +
"The road is covered with dust, and is not paved like the bigger streets in the\n" +
"town.\n";
 
}
