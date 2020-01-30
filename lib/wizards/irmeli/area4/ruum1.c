inherit "room/room";  



reset(arg) {

  add_exit("north","/wizards/irmeli/area4/ruum2.c");

  add_exit("out","/wizards/irmeli/area4/entrance.c");

  set_not_out(1); 



  short_desc = "Inside the Orthanc, tower of death";

  long_desc = "In front you opens the great hall of Orthanc, tower of death. The hall is\n"+

                "so high that you can't even see the top of it. If you look upwards you\n"+

                "can see about five floors until the darkness hides the rest. The walls\n"+

                "are very heavy and unharmed looking like some force is covering them\n"+

                "against time. The floor is made from marble and there is some cracks\n"+

                "on it.\n";

}

