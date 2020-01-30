inherit "room/room";

object monster;



reset(arg) {

  if(!present("gremlin 2")) { 

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

    move_object(clone_object("/wizards/irmeli/area4/gremlin2.c"),

    this_object());

}  



  if(arg) return;



  add_exit("east","/wizards/irmeli/area4/ruum18.c");

  add_exit("west","/wizards/irmeli/area4/ruum9.c");

  add_exit("northwest","/wizards/irmeli/area4/ruum16.c");

  add_exit("northeast","/wizards/irmeli/area4/ruum15.c");

  add_exit("southwest","/wizards/irmeli/area4/ruum11.c");

  add_exit("southeast","/wizards/irmeli/area4/ruum12.c");

  set_not_out(1);



  short_desc = "Inside the Dungeons of Orthanc, tower of death";

  long_desc = "A huge hall opens in front of your eyes making you amazed by handwork. You\n"+

                "can image how hard work it has been building this hall. There are two\n"+

                "cages builded in the ground under your feets. The mightiest prisoners\n"+   

                "were held there until they died.\n";

}





