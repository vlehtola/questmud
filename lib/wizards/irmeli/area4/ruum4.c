inherit "room/room";  



reset(arg) {

  add_exit("west","/wizards/irmeli/area4/ruum5.c");

  add_exit("east","/wizards/irmeli/area4/ruum3.c");

  set_not_out(1);



  short_desc = "Inside the Orthanc, tower of death";

  long_desc = "A small corridor leading you to the western-wing of this tower. You notice\n"+

                "that this corridor is leading you a bit down, meaby under the surface of\n"+

                "the earth. There is some dirty clothes lying on the floor.\n";

}               

