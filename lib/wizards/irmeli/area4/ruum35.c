inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin5.c"),

    this_object());

}  



  if(arg) return;



  add_exit("west","/wizards/irmeli/area4/ruum36.c");

  add_exit("east","/wizards/irmeli/area4/ruum34.c");

  set_not_out(1);



  short_desc = "Floor four inside the Orthanc, tower of death";

  long_desc = "A small corridor leading you to the western-wing in floor four. This long\n"+

                "corridor is builded about fourty feets above the surface of the earth.\n"+

                "There is something strange in this room. The walls have painted with\n"+

                "white paint.\n";

}

