inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city22.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/city27.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city24.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking in the southeast part of the city.\n"+
              "In west you can see the main road of the city of\n"+
              "Gnael, and behind the road you can see a huge mansion\n"+
              "rising towards the sky. In east you can see a few houses\n"+
              "and in the far southeast corner you can see somekind of a\n"+
              "market place. The streets are full of people and the air\n"+
              "is somewhat dusty. A small gust of wind is waving leaves\n"+
              "in nearby trees, even though everyone seems to be in a rush,\n"+
              "the city looks calm and peaceful.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in west";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "houses";
        items[5] = "Some small houses can be seen everywhere you look";
        items[6] = "leaves";
        items[7] = "The wind is waving some leaves in the nearby trees";

}
