inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city25.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/shop3.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/shop4.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/shop5.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking in the southeast part of the city.\n"+
              "In west you can see the main road of the city of\n"+
              "Gnael, and behind the road you can see a huge mansion\n"+
              "rising towards the sky. There is a small wooden sign\n"+
              "here. The streets are full of people\n"+
              "and the air is somewhat dusty. A small gust of\n"+
              "wind is waving leaves in nearby trees, even though everyone\n"+
              "seems to be in a rush, the city looks calm and peaceful.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in west";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "sign";
        items[5] = "General store in NORTH, Magic shop in EAST, Bakery in SOUTH";
        items[6] = "leaves";
        items[7] = "The wind is waving some leaves in the nearby trees";

}
