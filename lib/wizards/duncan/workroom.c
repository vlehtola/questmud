inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("island","/wizards/duncan/island/mainentrance");

  short_desc = "Workroom designed for Duncan";
  long_desc = "A workroom is designed for Duncan. The walls are covered with pictures of\n"+
              "naked girls and fast cars. A oaken table is standing next to the north wall,\n"+
              "full of high piles of paper. A huge crystal-chandelier is hanging down from\n"+
              "the ceiling, lighting up the whole room. Wrinkled and used papers are\n"+
              "covering the floor.\n";

  property = allocate(1);
  property[0] = "no_summon";
}







