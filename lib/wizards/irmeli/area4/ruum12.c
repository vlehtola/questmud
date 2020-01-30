inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

}  



  if(arg) return;



  add_exit("south","/wizards/irmeli/area4/ruum14.c");

  add_exit("northwest","/wizards/irmeli/area4/ruum10.c");

  set_not_out(1);



  short_desc = "Inside the Dungeons of Orthanc, tower of death";

  long_desc = "You are walking in a small corridor leading you to the killers cages. There\n"+

                "were a strong frames in front of the prison cage. There were also a big\n"+

                "guards in front of the prison cage around the clock, but nowadays there\n"+   

                "is just the memory of them.\n";

}





