inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("south",AREA+"r2.c");
  add_exit("southeast",AREA+"path1.c");
  add_exit("southwest",AREA+"r3.c");
  add_exit("west",AREA+"r5.c");
  add_exit("northwest",AREA+"r7.c");

  /* give the description for the room (M) */
  short_desc = "Dense forest";
  long_desc = "Many tall and considerably old oak trees are growing here. "+
              "Forest is more quiet and still here than in western parts of the forest. "+
              "There seems to be a hill somewhere northeast from here. "+
              "The bushes in southeast from here are impassable except the "+
              "narrow winding path going through them.\n";


  items = allocate(14);
  items[0] = "trees";
  items[1] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss. "+
             "One tree is the biggest one you've seen here, "+
             "it seems also easy to climb";
  items[2] = "oaks";
  items[3] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss. "+
             "One tree is the biggest one you've seen here, "+
             "it seems also easy to climb";
  items[4] = "oaktrees";
  items[5] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss. "+
             "One tree is the biggest one you've seen here, "+
             "it seems also easy to climb";
  items[6] = "tree";
  items[7] = "One oak is bigger than other trees around it. "+
             "It's bark is very thick and covered with moss. "+
             "Branches of the tree are low, "+
             "making it possible to climb up to the tree";                    
  items[8] = "hill";
  items[9] = "The hill northeast from here seems to be "+
             "the highest place of this forest. There must be quite "+
             "a view from top of that hill, since the ocean is near";
  items[10] = "bushes";
  items[11] = "These bushes are ridiculously overgrown, no one "+
             "could go through them without something sharp like an axe. "+
             "Luckily there is a clearing in bushes for path to go through them";
  items[12] = "path";
  items[13] = "A narrow path winding through the bushes, up to the hill";


}

