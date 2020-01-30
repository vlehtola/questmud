inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin3.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin3.c"),

    this_object());

}  



  if(arg) return;

  

  add_exit("east","/wizards/irmeli/area4/ruum21.c");

  set_not_out(1);



  short_desc = "Floor two inside the Orthanc, tower of death";

  long_desc = "You are now at western-wing on floor two, but it ends right here.\n"+

                "You have now only one exit from this room and unfortunately\n"+

                "you need to go backwards, if you wan't see more big halls\n"+

                "and stuff.\n";

}

