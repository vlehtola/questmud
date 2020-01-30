inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelfig2.c"), 
    this_object());
}
  
  if(arg) return;

  add_exit("south","/wizards/irmeli/pena/ruum13.c");
  add_exit("east","/wizards/irmeli/pena/ruum11.c");
  set_not_out(1);

  short_desc = "Small corridor leading you deeper in darkness";
  long_desc = "This is a small corridor leading you down under the surface. You notice\n"+
                "that the floor is covered by water. The walls are all over covered with\n"+
                "something green and slimy.\n";   
}


