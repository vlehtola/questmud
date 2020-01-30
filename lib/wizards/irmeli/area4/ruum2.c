inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin.c"),

    this_object());

}  



  if(arg) return;



  add_exit("north","/wizards/irmeli/area4/ruum3.c");

  add_exit("south","/wizards/irmeli/area4/ruum1.c");

  set_not_out(1);



  short_desc = "Inside the Orthanc, tower of death";

  long_desc = "You are standing in the middle of this big corridor leading you more deeper\n"+

                "in the darkness. This big corridor is so big that you can't even see the\n"+

                "the walls because the darkness hides them. A terrible smell comes from\n"+   

                "old corpses of warrior making you puke on your shoes.\n";

}






