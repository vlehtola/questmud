#define AREAPATH "wizards/nalle/rebirth/"

inherit AREAPATH+"rb_map";
inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  add_exit("northeast", AREAPATH+"path04");
  add_exit("southwest", AREAPATH+"a9");
  add_exit("south", AREAPATH+"a10");
  add_exit("southeast", AREAPATH+"a11");
  short_desc = "The northern part of a verdant plateau";
  long_desc =
"You have arrived to a small plateau that extends to the south\n"+
"and is limited by the steep cliffs of the mountain to the south,\n"+ 
"west and east. The trail at the north end of the plateau seems\n"+
"to be the only place where the climb down is manageable. You hear\n"+
"faint clatter and speech from the south.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {  
    if (arg) {
        return 0;
    }

  if(this_player()->query_terminal()) 
  write("\n"+cmap_a+"\n"); else 
  write("\n"+map_a+"\n");  
  
   return 1;  
}  

