inherit "room/room";
object monster;

reset(arg) { 
        
         if (!present("catfolk 1")) {
         move_object("wizards/jenny/gnael/mosut/catfolk_child1.c", this_object());
        }
         if (!present("catfolk 2")) {
         move_object("wizards/jenny/gnael/mosut/catfolk_child2.c", this_object());
        }
         if (!present("catfolk 3")) {
         move_object("wizards/jenny/gnael/mosut/catfolk_child3.c", this_object());
        }

        if(arg) return;

        add_exit("down","/wizards/jenny/gnael/huoneet/house1.c");

  short_desc = "You are in the second floor of the house";
  long_desc = "You are in the second floor of the house, there are toys\n"+
              "everywhere around you and other stuff that kids\n"+
              "use when they play their silly games. You can see a\n"+
              "huge mansion rising towards the sky when you look out\n"+
              "of the window. Wooden stairs are leading downstairs\n"+
              "nearby.\n";

        items = allocate(10);
        items[0] = "toys";
        items[1] = "Weird looking toys for children";
        items[2] = "stuff";
        items[3] = "Weird stuff that kids use for having fun";
        items[4] = "mansion";
        items[5] = "A huge mansion is located bit southeast from here";
        items[6] = "window";
        items[7] = "The window is pretty dirty, but you can still see a huge mansion nearby";
        items[8] = "stairs";
        items[9] = "Wooden stairs are leading downstairs";
}
