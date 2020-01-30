inherit "room/room";







reset(arg) {



  add_exit("south","/wizards/irmeli/bwp/lost1.c");



  add_exit("north","/wizards/irmeli/bwp/lost1.c");



  add_exit("east","/wizards/irmeli/bwp/lost1.c");



  add_exit("west","/wizards/irmeli/bwp/room11.c");



  short_desc = "On a small path, leading through the dense forest";



  long_desc = "A small path leads through the densest part of the forest. In every direction\n"+ 



                "the forest looks similar, dense everywhere. The standing crop looks very old\n"+



                "and decayed in here. The trees are swaying in the wind dangerously, like\n"+   



                "they would break off in two and fall over to the ground.\n";

            

  property = allocate(1);



  property[0] = "no_summon";



}











