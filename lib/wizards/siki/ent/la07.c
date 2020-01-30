inherit "room/room";

reset(arg) {

   add_exit("east","/wizards/siki/ent/la08");
   add_exit("west","/wizards/siki/ent/la06");
   short_desc = "A huge labyrinth.";
   long_desc = "A narrow tunnel leading nowhere. A small stream of blood\n"+
               "arrives from the east, crosses the room and has created\n"+
               "a pool in the middle of the room.\n";

items = allocate(6);
items[0] = "pool";
items[1] = "A pool of fresh red blood";
items[2] = "stream";
items[3] = "The stream is small, but it runs quite fast";
items[4] = "blood";
items[5] = "Dark red blood all over the room in different forms";
   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);




}

