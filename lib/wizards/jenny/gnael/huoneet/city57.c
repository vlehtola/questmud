inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/city56.c");
        add_exit("enter","/wizards/jenny/gnael/huoneet/mayor2.c");

    short_desc = "You are walking on a street";
    long_desc = "You are walking on a street, ahead of you in west you\n"+
              "can see the main road of Gnael, and if you look even more further\n"+
              "west you can see the a big building standing calmly in the wind.\n"+
              "The mayor's house is standing next to you in east and in southwest\n"+
              "there is a massive looking mansion rising towards the sky.\n"+
              "The citywall and some trees is the only thing you can see in north.\n";

        items = allocate(6);
        items[0] = "building";
        items[1] = "You can see a big stone made building in west";
        items[2] = "mansion";
        items[3] = "A huge mansion is rising towards the sky in southwest";
        items[4] = "house";
        items[5] = "The mayor's house is standing next to you in east";

}
