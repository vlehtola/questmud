inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 1")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelfig3.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("west","/wizards/irmeli/pena/ruum15.c");
  add_exit("south","/wizards/irmeli/pena/ruum17.c");
  set_not_out(1);

  short_desc = "Long corridor leading you under the surface";
  long_desc = "This is a long corridor leading you under the surface. There are sand\n"+
                "and stones on the floor. You can hear footsteps coming from\n"+
                "corridor behind you.\n"; 
}


