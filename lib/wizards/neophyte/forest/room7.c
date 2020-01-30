inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "At the small path in forest";
        long_desc = "This is a sandy path to the beach. There are no more trees here,\n"+
                    "only small bushes are growing in the sand.\n";
    add_exit("south","/wizards/neophyte/forest/room8");
    add_exit("northeast","/wizards/neophyte/forest/room6");
            items = allocate(6);
                    items[0] = "trees";
                    items[1] = "Branches of the trees are moving in the wind";
                    items[2] = "path";
                    items[3] = "It is going in that thick forest";
                    items[4] = "animals";
                    items[5] = "They are jumping wildy in the forest";
}
