inherit "room/room";
object bird,bird2,bird3,bird4,bird5,bird6;

reset(arg) { 
        
         if (!present("bird")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/pigeon.c"), this_object());
        }

         if (!present("bird2")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/pigeon.c"), this_object());
        }

         if (!present("bird3")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/pigeon.c"), this_object());
        }

         if (!present("bird4")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/pigeon.c"), this_object());
        }

         if (!present("bird5")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/pigeon.c"), this_object());
        }

         if (!present("bird6")) {
         move_object(clone_object("/wizards/jenny/gnael/mosut/pigeon.c"), this_object());
        }

        if(arg) return;

        add_exit("north","/wizards/jenny/gnael/huoneet/garden1.c");

  short_desc = "You are in a beautiful garden";
  long_desc = "You have arrived into a beautiful garden. Everywhere\n"+
              "you look you can see weird and exotic looking plants,\n"+
              "trees and even mushrooms. Birds are flying over the\n"+
              "garden and some people have brought food for them to eat.\n"+
              "Strong looking iron bars are surrounding the garden, but\n"+
              "you can see the city around the garden. You also see\n"+
              "a small wooden door in north.\n";

        items = allocate(14);
        items[0] = "plants";
        items[1] = "Exotic looking plants are growing here";
        items[2] = "trees";
        items[3] = "Some exotic looking trees surround you";
        items[4] = "mushrooms";
        items[5] = "Some weird looking mushrooms are growing nearby";
        items[6] = "birds";
        items[7] = "Cute looking birds are flying here and there";
        items[8] = "food";
        items[9] = "Some people have brought food for the birds";
        items[10] = "bars";
        items[11] = "Strong looking iron bars are protecting the garden";
        items[12] = "door";
        items[13] = "A small wooden door leading back to the mansion";
}
