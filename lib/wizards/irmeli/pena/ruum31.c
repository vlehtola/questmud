inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelguard2.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelguard2.c"), 
    this_object());
}
  
  if(arg) return;

  add_exit("north","/wizards/irmeli/pena/ruum32.c");
  add_exit("out","/wizards/irmeli/pena/ruum13.c");
  set_not_out(1);

  short_desc = "Big room where guards live";
  long_desc = "You are standing in the middle of guards room. The room is very beatiful\n"+
                "and made with the old-fashion way. There are two guard huts next to\n"+
                "the corridor which is leading north.\n";   
}


