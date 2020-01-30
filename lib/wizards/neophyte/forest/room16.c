inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "At the small path in forest";
        long_desc = "You are walking in the path. Trees near the path are much taller and\n"+
                    "better shaped then before, maybe its something to do with the ground,\n"+
                    "which is much better place to grow. This forest surely is full life.\n";
    add_exit("northwest","/wizards/neophyte/forest/room15");
    add_exit("east","/wizards/neophyte/forest/room17");
            items = allocate(6);
                    items[0] = "trees";
                    items[1] = "Branches on the tree are moving in the wind";
                    items[2] = "path";
                    items[3] = "It is going in that hay field";
}
