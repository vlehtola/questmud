inherit "room/room";

reset(arg) {


   add_exit("southwest","/wizards/siki/ent/la05");
   add_exit("east","/wizards/siki/ent/la10");

   short_desc = "A huge labyrinth.";
   long_desc = "A dark narrow tunnel leading somewhere. The walls are ice\n"+
               "cold and there are some sharp shapes. A huge engraving decorates\n"+
               "the wall.\n";

items = allocate(2);
items[0] = "engraving";
items[1] = "Something written in a strange language";

   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);




}


