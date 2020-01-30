inherit "room/room";  



reset(arg) {

  add_exit("east","/wizards/irmeli/bwp/room30.c");

  add_exit("back","/wizards/irmeli/bwp/room8.c"); 



  short_desc = "At east side the other side of the river";

  long_desc = "You are at the east side of the river. The bank of the river is full of sand,\n"+

                "gravel sand. All the trees has been chopped down from this side of the\n"+

                "river. Here is only one tree, the old and decayed tree, which has falled\n"+

                "across the river. \n";


  property = allocate(1);

  property[0] = "no_summon";

}

