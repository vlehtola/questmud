inherit "room/room";
object monster;

reset(arg) { 
        
         if (!present("woman")) {
         move_object("wizards/jenny/gnael/mosut/hungry_woman.c", this_object());
        }

        if(arg) return;

        add_exit("out","/wizards/jenny/gnael/huoneet/city14.c");

  short_desc = "Inside a house";
  long_desc = "You have entered a poor, but still somewhat\n"+
              "cosy looking house. There are few chairs and a\n"+
              "very small table on the middle of the room and\n"+
              "some leaves have been placed in the corner to\n"+
              "resemble a bed. There is also a small fireplace\n"+
              "in a corner.\n";

        items = allocate(8);
        items[0] = "chairs";
        items[1] = "Fragile looking chairs surrounding the table";
        items[2] = "table";
        items[3] = "Very small table made of wood";
        items[4] = "leaves";
        items[5] = "A bed made of leaves";
        items[6] = "fireplace";
        items[7] = "A small fireplace is placed into a corner";
}
