inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("north",AREA+"r7.c");
  add_exit("east",AREA+"r4.c");
  add_exit("southeast",AREA+"r2.c");
  add_exit("south",AREA+"r3.c");
  add_exit("west",AREA+"r6.c");
  
  /* give the description for the room (M) */
  short_desc = "In the middle of the forest.";
  long_desc = "Lots of trees grow here, "+
              "which is typical for forests. "+
              "Air is filled with animal sounds, "+
              "although few of them can actually be seen. "+
              "Some clear sky begins to show through treetops north from here. "+
              "Maybe there's good view around "+
              "since the ground is getting higher there too. \n";

  items = allocate(8);
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
  items[4] = "treetops";
  items[5] = "Treetops are high above you, "+
             "they are hardly letting any light in";
  items[6] = "animals";
  items[7] = "They cannot actually be seen, "+
             "but all those noises around tell that "+
             "lots of animals are hiding somewhere here";

}
