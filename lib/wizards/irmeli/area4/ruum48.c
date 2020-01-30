inherit "room/room";  

reset(arg) {
  add_exit("west","/wizards/irmeli/area4/ruum49.c");
  add_exit("east","/wizards/irmeli/area4/ruum51.c");
  add_exit("south","/wizards/irmeli/area4/ruum53.c");
  add_exit("north","/wizards/irmeli/area4/ruum55.c");
  add_exit("down","/wizards/irmeli/area4/ruum41.c");
  set_not_out(1);

  short_desc = "Floor six inside the Orthanc, tower of death";
  long_desc = "You are now standing on the top of this tower. The tower sways in the wind\n"+
                "like thin blade of grass. There is exit to the north leading probably to\n"+
                "the balcony or roof. There used to be a huge steel door blocking to\n"+
                "the north, but now there is only remains of it.\n"; }
