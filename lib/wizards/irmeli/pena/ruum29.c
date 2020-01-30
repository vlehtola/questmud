inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig4.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("south","/wizards/irmeli/pena/ruum26.c");
  add_exit("west","/wizards/irmeli/pena/ruum28.c");
  add_exit("east","/wizards/irmeli/pena/ruum30.c");
  add_exit("southwest","/wizards/irmeli/pena/ruum27.c");
  add_exit("southeast","/wizards/irmeli/pena/ruum25.c");
 
  short_desc = "Huge field in the Valley of Angels";
  long_desc = "You are walking in middle of huge field. The ground is wet. There is\n"+
                "some footprints left to the mud. Old corn or something like\n"+
                "that is smelling strongly.\n";   
}


