inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin5.c"),

    this_object());

}  



  if(arg) return;



  add_exit("south","/wizards/irmeli/area4/ruum40.c");

  add_exit("north","/wizards/irmeli/area4/ruum34.c");

  set_not_out(1);



  short_desc = "Floor four inside the Orthanc, tower of death";

  long_desc = "This is a long corridor leading you to southwards and northwards. The walls\n"+

                "are still painted with the white paint. If you wonder why the white paint\n"+

                "you need to ask from the gods. The floor begins to feel a bit\n"+

                "unsubstantial making you shiver with fear. There are some\n"+

                "paintings hanging from the wall.\n";

}

