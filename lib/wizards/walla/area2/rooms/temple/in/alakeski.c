inherit "room/room";
 
  reset(arg) {
 
  add_exit("south","/wizards/walla/area2/rooms/tasanko/gateway");
  add_exit("north","/wizards/walla/area2/rooms/temple/in/keski");
  add_exit("west","/wizards/walla/area2/rooms/temple/in/alavasen");
  add_exit("east","/wizards/walla/area2/rooms/tepmle/in/alaoikea");
  add_exit("northeast","/wizards/walla/area2/rooms/temple/in/oikeakeski");
  add_exit("northwest","/wizards/walla/area2/rooms/temple/in/vasenkeski");
  short_desc = "inside the great walls of the temple";
  long_desc =
"You have arrived in a courtyard. The ground is paved with cobblestones,\n" +
"and you can see a large bonsai tree growing in the middle.\n" +
"You can hear voices of swords clanging in the distance, and a faint scent\n" +
"of incense is coming from up ahead.\n";
 
}
