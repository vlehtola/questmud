inherit "room/room";

reset(arg) {

   add_exit("west","/wizards/siki/ent/la01");
   add_exit("southeast","/wizards/siki/ent/la03");

   short_desc = "A huge labyrinth.";
   long_desc = "It seems that the infinite maze leads nowhere. The tunnel\n"+
               "has been build inside solid rock. The walls are covered with\n"+
	       "green thick slime. There is a strange arrow on the wall\n"+
               "pointing west.\n";


   items = allocate(4);
   items[0] = "slime";
   items[1] = "Extremely thick green slime that's slowly dripping from the ceiling";
   items[2] = "arrow";
   items[3] = "An arrow traced out of blood on the wall. It points to the west";

   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);

  


}
 

