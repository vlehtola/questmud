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



  add_exit("west","/wizards/irmeli/area4/ruum23.c");

  set_not_out(1);



  short_desc = "Floor two inside the Orthanc, tower of death";

  long_desc = "You are now at eastern-wing on floor two, but it ends right here. You have\n"+

                "now only one exit from this room and unfortunately you need to go\n"+

                "backwards, if you wan't see more big halls. This room doesn't\n"+

                "look very domestic.\n";

}

