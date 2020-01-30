inherit "room/room";  



reset(arg) {

  add_exit("west","/wizards/irmeli/area4/ruum35.c");

  add_exit("east","/wizards/irmeli/area4/ruum37.c");

  add_exit("up","/wizards/irmeli/area4/ruum41.c");

  add_exit("south","/wizards/irmeli/area4/ruum39.c");

  add_exit("down","/wizards/irmeli/area4/ruum27.c");

  set_not_out(1);



  short_desc = "Floor four inside the Orthanc, tower of death";

  long_desc = "You are standing in a similar hall like the ealier ones under your feets.\n"+

                "The walls are covered with paintings, pictures and curtains. Hall\n"+

                "looks domestic and beatiful in a warriors eyes, which has overcome\n"+

                "throught difficult battles and find its way in here. There is a\n"+

                "small fireplace on the northern wall.\n";

}

