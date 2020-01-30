inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "At the small path in forest";
        long_desc = "You are walking in the path. Trees near the path are much taller and\n"+
                    "better shaped than before, maybe it has something to do with the ground,\n"+
                    "which is much better place to grow. This forest certainly is full of life.\n";
    add_exit("south","/wizards/neophyte/forest/room4");
    add_exit("southeast","/wizards/neophyte/forest/room16");
            items = allocate(4);
                    items[0] = "trees";
                    items[1] = "Trees look much healthy and taller";
                    items[2] = "path";
                    items[3] = "Path looks much easier to be followed then before";
}
