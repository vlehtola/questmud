inherit "room/room";

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) { return 0; }
   cat("/wizards/walla/jericho/maps/cs");
   return 1;
}
reset(arg) {

  add_exit("north","/wizards/walla/test/huone");
  short_desc = "Grand place";
  long_desc =
"You are standing in the middle of the city. The walls can be seen\n" +
"in the distance. You notice that the ground has been newly paved\n" +
"with white marble from distant lands. A thing that strikes you, is\n" +
"the lack of animals in the town. The commotion in the city has not\n"
"quite yet started, as people have only just started settling.\n";

}
catch_tell(string str) {
 string tmp1;
 if(sscanf(str, "%s arrives from %s.", tmp1) == 1) {
 shout(tmp1+" arrives.\n");
 tell_object(find_player(tmp1), "jees.\n");
 }
}
