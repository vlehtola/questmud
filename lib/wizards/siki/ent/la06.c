inherit "room/room";

reset(arg) {

   add_exit("north","/wizards/siki/ent/la05");
   add_exit("east","/wizards/siki/ent/la07");
   add_exit("southwest","/wizards/siki/ent/la31");
   short_desc = "A huge labyrinth.";
   long_desc = "A small crossing. The tunnels are narrow and dusty. A strong\n"+
               "smell of death fills the air and the slime on the walls slowly\n"+
               "drips. Huge spiderwebs cover the ceiling and the upper walls.\n";

items = allocate(4);
items[0] = "spiderweb";
items[1] = "A huge spiderweb in the corner of the room. It is dusty and torn";
items[2] = "spiderwebs";
items[3] = "Huge spiderwebs all over the ceiling. Old peaces of rotten flesh hang in them";
   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);




}


