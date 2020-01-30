inherit "room/room";  



object monster;







reset(arg) {



  if(!present("woodcutter")) { 



    move_object(clone_object("/wizards/irmeli/bwp/monsters/woodcutt.c"),



    this_object());



}  



  if(arg) return;





  add_exit("east","/wizards/irmeli/bwp/room47.c");



  add_exit("north","/wizards/irmeli/bwp/room43.c"); 



  add_exit("west","/wizards/irmeli/bwp/room41.c");



  short_desc = "In the middle of the lumbering at east side of the river";



  long_desc = "All the trees has been chopped down from this side. Everywhere, as far as the\n"+



                "eye can reach, there is not even a single tree standing. The ground is full\n"+



                "of stump of the trees. There are big woodpiles all over the lumbering. The\n"+



                "wasteful utilization of forests seems not the be important in here.\n";



              







  property = allocate(1);



  property[0] = "no_summon";



}



