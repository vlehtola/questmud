inherit "room/room";

reset(arg) {
 
  add_exit("north","/wizards/irmeli/area2/ruum2.c");
  add_exit("out","/wizards/irmeli/area2/entrance");
  set_not_out(1);

  short_desc = "A mine gallery in an old mine";
  long_desc = "A mine gallery in an old and abandoned mine. This narrow mine gallery is poor\n"+
                "in design. The mine gallery is too small and not suited for mining. Mine\n"+
                "workers excavated blast stones from this mine. The blast stones were used\n"+
                "for the construction of the walls of the city. A wooden sign is hanging\n"+
                "from the ceiling.\n";

  items = allocate(2);
  items[0] = "sign";
  items[1] = "It reads on the sign: DANGER!! DO NOT ENTER!! HIGH-EXPLOSIVE GAS!!";

}




