inherit "room/room";





reset(arg) {







  add_exit("south","/wizards/irmeli/bwp/lost3.c");



  add_exit("north","/wizards/irmeli/bwp/lost3.c");



  add_exit("east","/wizards/irmeli/bwp/lost3.c");



  add_exit("west","/wizards/irmeli/bwp/lost3.c");







  short_desc = "Lost in the dense forest";



  long_desc = "Every tree looks similar in this part of the forest. The forest is dense in\n"+ 



                "here, denser than anywhere else. You have lost the main path as also as the\n"+



                "sense of direction. The ground is covered with old brown leaves from the\n"+



                "trees around the place. The map of this forest would be useful now.\n";







  property = allocate(1);



  property[0] = "no_summon";



}











