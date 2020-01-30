inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit2.c"),
    this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/irmeli/area2/ruum10.c");
  set_not_out(1);
  
  short_desc = "Dead end";
  long_desc = "This tiny gallery collapsed totally in the explosion. They never\n"+
                "finished building it after that. There are a few picks and\n"+
                "shovels on the ground.\n";   
 }
