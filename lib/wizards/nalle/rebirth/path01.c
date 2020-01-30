#define AREAPATH "wizards/nalle/rebirth/"

inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("north",AREAPATH+"path02");
  add_exit("south",AREAPATH+"path02");
  short_desc = "A path leading south";
  long_desc =
"A small path leads south, up a fairly steep hill. The path\n"+
"does not seem to be used very much, grass and hay have consequently\n"+ 
"started to cover the trail, making it difficult to notice from a\n"+
"distance. The silent chitter of insects and small rodents adds to\n"+
"to the location's peaceful feel.\n";
}

