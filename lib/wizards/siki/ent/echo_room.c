inherit "room/room";
inherit "/wizards/siki/ent/echo";


reset(arg) {
   add_exit("east","/wizards/siki/ent/la02");

   short_desc = "A dead end.";
   long_desc = "A dead end in the labyrinth. The tunnel has been build\n"+
               "inside solid rock. The walls are covered with green thick\n"+
               "slime. The tunnel is extremely narrow at this point.\n";

   set_light(3);

   items = allocate(2);
   items[0] = "slime";
   items[1] = "Extremely thick green slime that's slowly dripping from the ceiling";

   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);

  
}
 
