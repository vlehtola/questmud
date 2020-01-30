inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit6.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit6.c"), 
    this_object());
}  

  if(arg) return;

  add_exit("west","/wizards/irmeli/area2/ruum24.c");
  add_exit("east","/wizards/irmeli/area2/ruum25.c");
  add_exit("south","/wizards/irmeli/area2/ruum26.c");
  add_exit("up","/wizards/irmeli/area2/ruum15.c");
  set_not_out(1);
  
  short_desc = "Central gallery in the bottom level";
  long_desc = "You are now in the bottom level. This level is about hundred meters below\n"+
                "surface of the earth. It is freezing in this level. Some icicles are\n"+
                "hanging from the wall.\n";   
}


