inherit "room/room";
object monster;

reset(arg) {
  if(!present("hobbit")) { 
    move_object(clone_object("/wizards/irmeli/area2/king.c"),
    this_object());
}  

  if(arg) return;

  add_exit("north","/wizards/irmeli/area2/ruum26.c");
  set_not_out(1);
  
  short_desc = "Chamber of hobbit king";
  long_desc = "A huge chamber where the king of hobbits lives. There is kings bed at the far\n"+
                "end of the chamber. There is also a fireplace burning in the middle of\n"+
                "chamber. \n";   
}


