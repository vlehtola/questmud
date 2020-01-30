inherit "room/room";

  reset(arg) {
    if(arg) return;


  add_exit("south","/wizards/siki/island/v_map: 19 5");

  short_desc = "Entrance to a valley";
  long_desc = "A deep valley inside a mountain. The path is quite narrow\n"+
              "yet easy to walk. The ground is quite soft and there are some\n"+
              "footprints. Some grass grows here and there.\n";

  items = allocate(4);
  items[0] = "footprints";
  items[1] = "Huge footprints made by some big creatures";
  call_other("/wizards/siki/island/v_map", "dodi");
 }
