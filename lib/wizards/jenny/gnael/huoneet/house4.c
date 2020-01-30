inherit "room/room";

reset(arg) {

        add_exit("out","/wizards/jenny/gnael/huoneet/city27.c");

  short_desc = "You are in a house";
  long_desc = "You are in a house, there is a small cuddly looking\n"+ 
              "bed in one corner. A small iron pot is placed on\n"+
              "the center of the room and some wooden shelves are\n"+
              "hanging on the wall with many piles of silver dishes\n"+
              "placed on them.\n";

        items = allocate(8);
        items[0] = "beds";
        items[1] = "A small cuddly looking bed";
        items[2] = "pot";
        items[3] = "A small iron pot with some delicious looking liquid inside";
        items[4] = "shelves";
        items[5] = "Wooden shelves are hanging on the wall";
        items[6] = "dishes";
        items[7] = "Piles of clean silver dishes are placed on the shelves";
}
