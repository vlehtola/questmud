inherit "room/room";
 
 
reset(arg) {
  add_exit("inni","/world/city/inn.c");
  add_exit("area1","/wizards/grathlek/area1/eroom1.c");
  add_exit("kukkuu","/wizards/grathlek/kukkuu/huone.c");

  short_desc = "Grathlek's Workroom & Jorma's Porno Luola.";
  long_desc = "This is Grathleks workroom you can see a statue.\n"+
              "of Grathlek.\n";

    items = allocate(4);
    items[0] = "statue";
    items[1] = "This statue looks like Gratlek.\n";
 
}
