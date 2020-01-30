inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("north",AREA+"r5.c");
  add_exit("east",AREA+"r2.c");
  add_exit("northeast",AREA+"r4.c");
  add_exit("southeast",AREA+"r1.c");
  add_exit("west",AREA+"hole.c");
  add_exit("northwest",AREA+"r6.c");
  
  /* give the description for the room (M) */
  short_desc = "In the middle of the forest.";
  long_desc = "Lots of trees grow here, which is typical for forests. "+
              "Air is filled with animal sounds, although few of them can actually be seen. "+
              "Some sort of path, almost hidden by the vegetation, goes towards northwest.\n";
              

  items = allocate(10);
  items[0] = "trees";
  items[1] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss. "+
             "One tree seems to be bigger than others and "+
             "also easier to climb";
  items[2] = "tree";
  items[3] = "One oak is bigger than other trees around it. "+
             "It's bark is very thick and covered with moss. "+
             "Branches of the tree are low, "+
             "making it possible to climb up to the tree";                   
  items[4] = "animals";
  items[5] = "They cannot actually be seen, "+
             "but all those noises around tell that "+
             "lots of animals are hiding somewhere here";
  items[6] = "path";
  items[7] = "The path seems to be forgetten since "+
             "it seems almost unused. "+
             "However, more careful examination reveals some small footprints: "+
             "someone or something too small to be human has walked here recently";
  items[8] = "vegetation";
  items[9] = "The ground vegetation is vastly grown here, "+
             "almost covering a small path. "+
             "It seems few people have ever visited in these woods";

}
