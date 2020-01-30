#define AREAPATH "wizards/nalle/plateau/"

inherit "room/room";

object monster;

reset(arg) {
  if(arg) return;
  add_exit("out",AREAPATH+"12_-2");
  short_desc = "Inside an abandoned shack";
  long_desc =
"This shack seems to have been abandoned quite a long time ago. There\n"+
"is no door, and quite a thick layer of dead leaves has formed on the\n"+
"floor. A distinct smell of bat guano fills the room as you disturb the\n"+
"humid leaves that have been rotting away here for years. While being\n"+
"an ideal environment for small rodents and insects, you find the hut\n"+
"rather repulsive.\n";
}

