inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("out","/wizards/veron/areat/cotd/cs.c");
add_exit("northwest","/wizards/veron/areat/cotd/path.c");

  short_desc = "Mining office";

  long_desc = "The main office of the mining company. There are different-sized\n"+
              "rocks and boulders placed on shelves in the room. Pick-axes have\n"+
              "been hung to the walls. A large granite desk has been placed in\n"+
              "the middle of the room. The back door is open, leading to the\n"+
              "mountains.\n";
     set_not_out(1);           

  items = allocate(8);
  items[0] = "rocks";
  items[1] = "Different sized and shaped rocks and boulders placed on the shelves";
  items[2] = "boulders";
  items[3] = "Different sized and shaped rocks and boulders placed on the shelves";          
  items[4] = "pick-axes";
  items[5] = "The miners' tools have been hung to the walls";
  items[6] = "desk";
  items[7] = "A large granite desk in the middle of the room";

 	
  }
