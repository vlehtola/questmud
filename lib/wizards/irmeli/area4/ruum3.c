inherit "room/room";  
object monster;


reset(arg) {
  if(!present("guard 2")) {
    move_object(clone_object("/wizards/irmeli/area4/guard1.c"),
    this_object());
    move_object(clone_object("/wizards/irmeli/area4/guard1.c"),
    this_object());
}

if(arg) return;

  add_exit("west","/wizards/irmeli/area4/ruum4.c");

  add_exit("east","/wizards/irmeli/area4/ruum6.c");

  add_exit("up","/wizards/irmeli/area4/ruum20.c");

  add_exit("south","/wizards/irmeli/area4/ruum2.c");

  set_not_out(1);



  short_desc = "Inside the Orthanc, tower of death";

  long_desc = "A big hall opens in front of your eyes making you amazed with beaty. This\n"+

                "hall is smaller than the earlier main hall in this tower but this is\n"+

                "more domestic and beatiful. A small window on the northern wall\n"+

                "brings a small amount of light in here.\n";

}

