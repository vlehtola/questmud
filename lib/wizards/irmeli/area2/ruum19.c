inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit 2")) { 
    move_object(clone_object("/wizards/irmeli/area2/hobbit5.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area2/hobbit5.c"), 
    this_object());
}  

  if(arg) return;

  add_exit("south","/wizards/irmeli/area2/ruum18.c");
  set_not_out(1);
  
  short_desc = "Small storeroom for foods";
  long_desc = "This small storeroom was built here for storing food for miners. There are two\n"+
                "shelfs in the rear of room. Few boxes are lying on the floor waiting someone\n"+
                "to pick them up.\n";    
}


