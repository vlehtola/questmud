inherit "room/room";

reset(arg) {
 
  add_exit("east","/wizards/irmeli/area2/ruum4.c");
  set_not_out(1);

  short_desc = "A storeroom for mine equipment";
  long_desc = "A small room made for storing miners equipment. Miners stored here some of the\n"+
                "important mining equipments. Picks, miner's lamps and also lots of gunpowder\n"+
                "was stored in here. A small shelf standing against the wall at the back of\n"+
                "the room.\n";

  items = allocate(2);
  items[0] = "shelf";
  items[1] = "A small shelf is made of wood. Someone has forced it open and therefore there is nothing except pinch of gunpowder";
}


