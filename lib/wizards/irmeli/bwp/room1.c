inherit "room/room";  



reset(arg) {

  add_exit("north","/wizards/irmeli/bwp/room2.c");

  add_exit("out","/wizards/irmeli/bwp/entrance.c"); 



  short_desc = "A small path leading deeper in the forest";

  long_desc = "A small path is curving around the forest leading deeper in the woods. There\n"+

                "are lots of trees on the way, all looking a bit different than the usual\n"+

                "trees. Some of the trunks are deformed, mostly the old ones, because they\n"+

                "are pestilential. There are no leaves on branches of the trees. Someone\n"+

                "has cutted some trees from here, leaving behind some stumps.\n"; 



  property = allocate(1);

  property[0] = "no_summon";

}

