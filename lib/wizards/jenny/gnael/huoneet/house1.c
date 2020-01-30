inherit "room/room";
object monster;

reset(arg) { 
        
         if (!present("lady")) {
         move_object("wizards/jenny/gnael/mosut/catfolk_lady.c", this_object());
        }

        if(arg) return;

        add_exit("out","/wizards/jenny/gnael/huoneet/city3.c");
        add_exit("up","/wizards/jenny/gnael/huoneet/houseu1.c");

  short_desc = "You are in a house";
  long_desc = "You are in a house, in one corner there are two\n"+
              "beds. A small brass pot is placed on the center of\n"+
              "the room. Some shelves are hanging on the wall and\n"+
              "few piles of clay dishes are placed on the shelves.\n"+
              "Wooden stairs leading upstairs can be found from\n"+
              "the back of the room.\n";

        items = allocate(10);
        items[0] = "beds";
        items[1] = "Uncomfortable looking beds";
        items[2] = "pot";
        items[3] = "A small brass pot with some weird liquid inside";
        items[4] = "shelves";
        items[5] = "Wooden shelves are hanging on the wall";
        items[6] = "dishes";
        items[7] = "Piles of dirty clay dishes are placed on the shelves";
        items[8] = "stairs";
        items[9] = "Wooden stairs are leading upstairs";
}
