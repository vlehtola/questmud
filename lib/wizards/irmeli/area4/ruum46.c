inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin6.c"),

    this_object());

}  



  if(arg) return;



  add_exit("south","/wizards/irmeli/area4/ruum47.c");

  add_exit("north","/wizards/irmeli/area4/ruum41.c");

  set_not_out(1);



  short_desc = "Floor five inside the Orthanc, tower of death";

  long_desc = "This is a long corridor leading you to southwards and northwards. There are\n"+

                "lots of broken chairs lying all around the place reminding you from the\n"+

                "big fight between gremlin race and earlier inhabitants. There is also\n"+

                "a monument to those poor soldiers who killed in action.\n";

}

