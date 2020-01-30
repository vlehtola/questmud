inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel")) { 
    move_object(clone_object("/wizards/irmeli/pena/angel2.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("south","/wizards/irmeli/pena/ruum8.c");
  add_exit("north","/wizards/irmeli/pena/ruum10.c");

  short_desc = "Path leading to the big field";
  long_desc = "You are walking on path leading to the big field. You can smell old corn\n"+
                "from the field. There are some old and ugly trees around you. If you\n"+
                "look exactly ahead you can see the big field.\n";   
}



