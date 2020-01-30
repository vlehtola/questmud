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

  

  add_exit("east","/wizards/irmeli/area4/ruum49.c");

  set_not_out(1);



  short_desc = "Floor six inside the Orthanc, tower of death";

  long_desc = "You are now at western-wing on floor six, but unfortunately there is only\n"+

                "one exit and it's backwards. The cold air displaces the warm air in\n"+

                "here western-wing. Black curtains are hanging on the wall in front\n"+

                "the massive window making the darkness more powerful.\n";

}

