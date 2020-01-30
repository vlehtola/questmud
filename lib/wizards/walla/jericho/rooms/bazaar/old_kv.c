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
reset(arg) {
 
  add_exit("east","/wizards/walla/jericho/rooms/bazaar/keski");
  add_exit("south","/wizards/walla/jericho/rooms/bazaar/alavasen");
  short_desc = "In the bazaar";
  long_desc =
"You are standing in the western part of the bazaar. You can hear\n" +
"commotion coming from vendors all around you, aswell as music. This\n" +
"lot of the bazaar is empty, and a sign saying 'free, ask Tsila Tipak\n" +
"for prices' is planted here. The ground is covered with red dust, \n"
"which seems to have been coloured by blood.\n";
 
 
}
