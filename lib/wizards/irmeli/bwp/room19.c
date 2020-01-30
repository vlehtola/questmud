inherit "room/room";





reset(arg) {

  add_exit("enter","/wizards/irmeli/bwp/house1.c");

  add_exit("south","/wizards/irmeli/bwp/lost3.c");

  add_exit("north","/wizards/irmeli/bwp/lost3.c");

  add_exit("east","/wizards/irmeli/bwp/room18.c");

  add_exit("west","/wizards/irmeli/bwp/lost3.c");

  short_desc = "In front a small red hunting lodge in the middle of the forest";

  long_desc = "Here is a small in partly red hunting lodge in the middle of the forest. In\n"+ 

                "partly red, because most of the red paint has been worn out by time. The\n"+

                "hunting lodge looks quite slight with construction, because it's leaning\n"+   

                "a bit to right.\n";

            

  property = allocate(1);

  property[0] = "no_summon";

}





