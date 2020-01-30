#define AREAPATH "wizards/nalle/rebirth/"

inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("north",AREAPATH+"path01");
  add_exit("southeast",AREAPATH+"path03");
  short_desc = "A path leading up the hill";
  long_desc =
"The path continues south-east, further up the hill. The path\n"+
"does not seem to be used very much, grass and hay have consequently\n"+ 
"started to cover the trail. The hill is also gradually becoming\n"+
"steeper and there seem to be fewer trees here. Raspberry bushes\n"+
"and wild flowers grow to both sides of the trail.\n";
}

