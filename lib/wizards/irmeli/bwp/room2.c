inherit "room/room";  



reset(arg) {

  add_exit("north","/wizards/irmeli/bwp/room3.c");

  add_exit("south","/wizards/irmeli/bwp/room1.c"); 



  short_desc = "A small path leading deeper in the forest";

  long_desc = "The forest is denser and it's almost impassable from some places. A small\n"+

                "curving path leads through the dense forest. By following the path, as\n"+

                "well as possible, it's possible to get through the densest part of the\n"+

                "forest without getting lost. There are some decayed trees chopped down\n"+

                "to the ground by woodcutter. \n";



  property = allocate(1);

  property[0] = "no_summon";

}

