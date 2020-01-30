inherit "room/room";
object monster;



reset(arg) {
  if(arg) return;
  if(!present("spirit") && !random(1)) {
     move_object(clone_object("/wizards/devil/area/mobit/eqspirit.c"), this_object());
}

 add_exit("out","/wizards/devil/area/huoneet/r57.c");
 add_exit("north","/wizards/devil/area/huoneet/r62.c");

 short_desc = "Path leading to somewhere";
 long_desc = "You are walking on the small path which is leading\n"+
                      "to somewhere. The path is in a good condition in here,\n"+
                      "but further forward the path seems to be getting worse\n"+
                      "by the step. Some roaring can be heard from north.\n";
                      

}
