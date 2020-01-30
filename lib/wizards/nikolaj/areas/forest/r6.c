inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("northeast",AREA+"r7.c");
  add_exit("east",AREA+"r5.c");
  add_exit("southeast",AREA+"r3.c");
  
  /* give the description for the room (M) */
  short_desc = "Path descending out of the forest.";
  long_desc = "This place seems the be at outskirts of "+
              "the forest since fewer trees grow here. "+
              "Cool breeze blows from north, "+
              "smelling like a great ocean. "+
              "The path here seems to descend right down to the beach. "+
              "On it's way down the path seems to "+
              "lead through some little village.\n";
              


  items = allocate(6);
  items[0] = "path";
  items[1] = "A narrow winding path descending down to the beach. "+
             "There seems to be a village on its way";
  items[2] = "trees";
  items[3] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss";
  items[4] = "village";
  items[5] = "Village seems silent, no sign of anything living "+
             "when watching up here";

}
