inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

}  



  if(arg) return;



  add_exit("east","/wizards/irmeli/area4/ruum17.c");

  add_exit("southeast","/wizards/irmeli/area4/ruum10.c");

  set_not_out(1);



  short_desc = "Inside the Dungeons of Orthanc, tower of death";

  long_desc = "You are standing in a small prison cage, which belongs to thiefs and rapers.\n"+

                "You wonder how full the prisons have been here for years waiting for\n"+

                "getting rid of the sentence. There is a old chains hanging from the\n"+   

                "ceiling waiting for the next prisoner.\n";

}






