inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin6.c"),

    this_object());

}  



  if(arg) return;



  add_exit("east","/wizards/irmeli/area4/ruum45.c");

  add_exit("west","/wizards/irmeli/area4/ruum41.c");

  set_not_out(1);



  short_desc = "Floor five inside the Orthanc, tower of death";

  long_desc = "A small corridor leading you to the eastern-wing in floor five. Old figures\n"+

                "is painted on the dusty floor reminding from old good times. It was\n"+

                "probably picture from the old king, but now it is covered with dust.\n"+

                "There are mysterious hooks coming deep inside the wall.\n";

}

