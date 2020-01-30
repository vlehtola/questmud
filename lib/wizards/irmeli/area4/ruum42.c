inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin6.c"),

    this_object());

}  



  if(arg) return;



  add_exit("west","/wizards/irmeli/area4/ruum43.c");

  add_exit("east","/wizards/irmeli/area4/ruum41.c");

  set_not_out(1);



  short_desc = "Floor five inside the Orthanc, tower of death";

  long_desc = "A small corridor leading you to the western-wing in floor five. This long\n"+

                "corridor is builded about fifty feets above the surface of the earth.\n"+

                "There are some wall paintings and writings on the north wall but not\n"+

                "an usual writings.\n";

}

