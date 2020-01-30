inherit "room/room";
 
 
reset(arg) {
  add_exit("inni","/world/city/inn.c");
  add_exit("area1","/wizards/grathlek/area1/eroom1.c");
  add_exit("cave","/wizards/grathlek/workroom2.c");
  add_exit("hole","/wizards/grathlek/kukkuu/huone3.c");
 
  short_desc = "Grathlek's Workroom & Jorma's Porno Luola.";
  long_desc = "You can see a cave entrance in the\n"+
              "west, there is a sign over the cave.\n";

    items = allocate(4);
    items[0] = "sign";
    items[1] = "It reads:\n"+
               "This is Jorma's Porno Luola.\n";
}
