inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit3.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit3.c"), 
    this_object());
}  

  if(arg) return;

  add_exit("west","/wizards/irmeli/area2/ruum17.c");
  add_exit("east","/wizards/irmeli/area2/ruum20.c");
  add_exit("south","/wizards/irmeli/area2/ruum15.c");
  set_not_out(1);
  
  short_desc = "Tiny gallery in third level";
  long_desc = "This gallery is similar than earlier ones. But miners may have found \n"+
                "something in here because they have explode here a lot. There is\n"+
                "water flowing on the ground.\n";   
}


