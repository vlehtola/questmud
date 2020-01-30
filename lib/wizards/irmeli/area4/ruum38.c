inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin5.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin5.c"),

    this_object());

}  



  if(arg) return;

  

  add_exit("west","/wizards/irmeli/area4/ruum37.c");

  set_not_out(1);



  short_desc = "Floor four inside the Orthanc, tower of death";

  long_desc = "You are now at eastern-wing on floor four, but unfortunately there is only\n"+

                "one exit and it's backwards. Here is nothing remarkable except the\n"+

                "walls are painted with the white paint like any another wall in\n"+

                "here floor four.\n";

}

