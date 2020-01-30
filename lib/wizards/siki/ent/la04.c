inherit "room/room";

reset(arg) {

   add_exit("southeast","/wizards/siki/ent/la05");
   add_exit("southwest","/wizards/siki/ent/la03");
   short_desc = "A huge labyrinth.";
   long_desc = "A narrow tunnel leading deeper inside. The tunnel has been build\n"+
               "inside solid rock. The walls are covered with green thick\n"+
               "slime. There are some old bones on the floor.\n";


items = allocate(4);
items[0] = "slime";
items[1] = "Extremely thick green slime that's slowly dripping from the ceiling";
items[2] = "bones";
items[3] = "Different bones of all races are scattered around the room";


   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);




}

