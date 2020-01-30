inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  /* give the exits (M) */
  add_exit("south",AREA+"r1.c");
  add_exit("north",AREA+"r4.c");
  add_exit("west",AREA+"r3.c");
  add_exit("northwest",AREA+"r5.c");

  /* give the description for the room (M) */
  short_desc = "In the middle of the forest";
  long_desc = "Many tall and considerably old oak trees are growing here. "+
              "Forest is more quiet and still here than in western parts of the forest. "+
              "There seems to be a hill somewhere northeast from here, "
              "with a nice view, unquestionably.\n";
              
  items = allocate(12);
  items[0] = "oaks";
  items[1] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss. "+
             "One tree seems to be bigger than others and "+
             "also easier to climb";
  items[2] = "trees";
  items[3] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss. "+
             "One tree seems to be bigger than others and "+
             "also easier to climb";
  items[4] = "tree";
  items[5] = "One oak is bigger than other trees around it. "+
             "It's bark is very thick and covered with moss. "+
             "Branches of the tree are low, "+
             "making it possible to climb up to the tree";           
  items[6] = "oaktrees";
  items[7] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss. "+
             "One tree seems to be bigger than others and "+
             "also easier to climb";
  items[8] = "hill";
  items[9] = "The hill northeast from here seems to be "+
             "the highest place of this forest. There must be quite "+
             "a view from top of that hill, since the ocean is near";
  items[10] = "bark";
  items[11] = "Bark of the trees is very thick";


}

