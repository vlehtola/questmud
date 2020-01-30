inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("out","/wizards/luminarc/workroom");
  add_exit("north","/wizards/luminarc/mountain/room0");
  short_desc = "Bottom of the mountain";
  long_desc = "Huge mountain raises at front of you. looks almost like it reaches to\n"+
              "clouds. the top and middle part of the mountain is covered with white\n"+
              "snow. chilling air is moving everywhere around this mountain. bether \n"+
              "get some warm clothes before entering here\n"; 
  property = allocate(1);
  set_light(3);
}







