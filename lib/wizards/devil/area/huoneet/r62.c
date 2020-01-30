inherit "room/room";
object monster;



reset(arg) {
  if(arg) return;
  if(!present("mummy") && !random(1)) {
     move_object(clone_object("/wizards/devil/area/mobit/eqmummy.c"), this_object());
}
 add_exit("south","/wizards/devil/area/huoneet/r61.c");
 add_exit("north","/wizards/devil/area/huoneet/r63.c");

 short_desc = "Path leading to somewhere";
 long_desc = "You are walking on the small path which is leading\n"+
                      "to somewhere. The path is in a good condition in here,\n"+
                      "but continuing forward you the path looks more\n"+
                      "worse in every step you take. Some roaring can be heard\n"+
                      "from north.\n";

}
