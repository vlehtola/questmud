inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin3.c"),
    this_object());
}  

  if(arg) return;
  
  add_exit("east","/wizards/irmeli/area4/ruum24.c");
  add_exit("west","/wizards/irmeli/area4/ruum20.c");
  set_not_out(1);

  short_desc = "Floor two inside the Orthanc, tower of death";
  long_desc = "A small corridor leading you to the eastern-wing in floor two. This long\n"+
                "corridor is builded about twenty feets above the surface of the\n"+
                "earth. A terrible smell comes from the clothes, which are lying\n"+
                "on the floor next to your feets.\n";
}
