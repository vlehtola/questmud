inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin3.c"),

    this_object());

}  



  if(arg) return;

  

  add_exit("south","/wizards/irmeli/area4/ruum26.c");

  add_exit("north","/wizards/irmeli/area4/ruum20.c");

  set_not_out(1);



  short_desc = "Floor two inside the Orthanc, tower of death";

  long_desc = "You are standing in a corridor leading south and north. There is happening\n"+

                "something strange in the southwards, but you can't see or feel it from\n"+

                "this far. This corridor is regular like any corridor, but you can\n"+

                "sense the evil presence.\n";

}

