inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city24.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city26.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking in the southeast part of the city.\n"+
              "In west you can see the main road of the city of\n"+
              "Gnael, and behind the road you can see a huge mansion\n"+
              "rising towards the sky. In east you can see a few\n"+
              "odd looking shops. The streets are full of people\n"+
              "and the air is somewhat dusty. A small gust of\n"+
              "wind is waving leaves in nearby trees, even though everyone\n"+
              "seems to be in a rush, the city looks calm and peaceful.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in west";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "shops";
        items[5] = "There seems to be three different kind of shops in east";
        items[6] = "leaves";
        items[7] = "The wind is waving some leaves in the nearby trees";

}
