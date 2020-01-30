#define AREAPATH "wizards/nalle/rebirth/"+

inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("northeast", AREAPATH"path03");
  add_exit("southwest", AREAPATH"path05");
  short_desc = "A mountainous ledge";
  long_desc =
"The trail has led you to a steep mountainous ledge. Movement here\n"+
"is cumbersome as sharp rocks and spiked undergrowth gnaws into\n"+ 
"your ankles. The ascent seems to end after the ledge, however.\n"+
"It would seem possible that you are arriving to some sort of plateau\n"+
"shortly, whether seeing it is worth the climb is a different matter.\n";
}

