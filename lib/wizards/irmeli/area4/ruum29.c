inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin4.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin4.c"),

    this_object());

}  



  if(arg) return;

  

  add_exit("east","/wizards/irmeli/area4/ruum28.c");

  set_not_out(1);



  short_desc = "Floor three inside the Orthanc, tower of death";

  long_desc = "You are now at western-wing on floor three but it ends right here.\n"+

                "You have now only one exit from this room and unfortunately you\n"+

                "need to go backwards, if you wan't see more big halls and\n"+

                "stuff, but luckily the distances aren't so long in here.\n";

}

