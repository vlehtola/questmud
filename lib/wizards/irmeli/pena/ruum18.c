inherit "room/room";
object monster;

reset(arg) {
  if(!present("angel 2")) { 
    move_object(clone_object("/wizards/irmeli/pena/angelguard.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/pena/angelguard.c"),
    this_object());
}
  
  if(arg) return;

  add_exit("down","/wizards/irmeli/pena/ruum19.c");
  add_exit("north","/wizards/irmeli/pena/ruum17.c");
  set_not_out(1);

  short_desc = "Small room where guards live";
  long_desc = "This is a small room where the loyal guards of the crow lives. This is\n"+
                "not like regular room. There is two guardhuts next to enter to down.\n"+
                "Campfire has burned-out times ago.\n"; 
}


