inherit "room/room";
object monster;

reset(arg) { 
        
         if (!present("gnome")) {
         move_object("wizards/jenny/gnael/mosut/gnome_man.c", this_object());
        }

        if(arg) return;

        add_exit("out","/wizards/jenny/gnael/huoneet/city9.c");

  short_desc = "You are in a house";
  long_desc = "You are in a house, there is a small cuddly looking\n"+ 
              "bed in one corner. A small iron pot is placed on\n"+
              "the center of the room. Some wooden shelves are\n"+
              "hanging on the wall and many piles of clay dishes\n"+
              "are placed on the shelves.\n";

        items = allocate(8);
        items[0] = "beds";
        items[1] = "A small cuddly looking bed";
        items[2] = "pot";
        items[3] = "A small iron pot with some weird liquid inside";
        items[4] = "shelves";
        items[5] = "Wooden shelves are hanging on the wall";
        items[6] = "dishes";
        items[7] = "Piles of dirty clay dishes are placed on the shelves";
}
