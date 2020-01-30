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

  add_exit("south","/wizards/walla/test/huone2");
  short_desc = "Grand place";
  long_desc =
"You are standing in the middle of the city. The walls can be seen\n" +
"in the distance. You notice that the ground has been newly paved\n" +
"with white marble from distant lands. A thing that strikes you, is\n" +
"the lack of animals in the town. The commotion in the city has not\n"
"quite yet started, as people have only just started settling.\n";

}
joku_tuli(string str) {
tell_object(find_player(str), "tulit!\n");
shout(str+" tuli!\n");
return 1;
}




