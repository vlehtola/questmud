inherit "room/room";  

reset(arg) {
  add_exit("west","/wizards/irmeli/area4/ruum21.c");
  add_exit("east","/wizards/irmeli/area4/ruum23.c");
  add_exit("up","/wizards/irmeli/area4/ruum27.c");
  add_exit("south","/wizards/irmeli/area4/ruum25.c");
  add_exit("down","/wizards/irmeli/area4/ruum3.c");
  set_not_out(1);

  short_desc = "Floor two inside the Orthanc, tower of death";
  long_desc = "You have fighted your way to here in a big hall on floor two. This hall is\n"+
                "builded same way like the hall, which is under you. You are now about twenty\n"+
                "feets above the surface of the earth making you feel a bit dizzy. It's\n"+
                "a bit easier to breath because fresh air has collected in here.\n";
}
