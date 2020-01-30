inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin7.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin7.c"),

    this_object());

}  



  if(arg) return;

  

  add_exit("west","/wizards/irmeli/area4/ruum51.c");

  set_not_out(1);



  short_desc = "Floor six inside the Orthanc, tower of death";

  long_desc = "You are now at eastern-wing on floor six, but unfortunately there is only\n"+

                "one exit and it's backwards. A huge pillar rises from the floor\n"+

                "through the roof approaching the sky. The pillar was probably\n"+

                "build for prop up the balcony above you.\n";

}

