inherit "room/room";
object monster;

reset(arg) {
  if(!present("gremlin")) { 
    move_object(clone_object("/wizards/irmeli/area4/gremlin4.c"),
    this_object());
}  

  if(arg) return;

  add_exit("west","/wizards/irmeli/area4/ruum29.c");
  add_exit("east","/wizards/irmeli/area4/ruum27.c");
  set_not_out(1);

  short_desc = "Floor three inside the Orthanc, tower of death";
  long_desc = "A small corridor leading you to the western-wing in floor three. This long\n"+
                "corridor is builded about thirty feets above the surface of the earth.\n"+
                "You can feel the wind raping the outwalls with ultimate power and\n"+
                "making this tower wobble a bit.\n";
}
