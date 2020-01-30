inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "At the small path in forest";
        long_desc = "You are walking in the path. The forest starts to become thinner\n"+
                    "in your eyes. There are lots of different bushes here and they all\n"+
                    "grow near the path. Far to the east can be seen a field.\n";
    add_exit("west","/wizards/neophyte/forest/room16");
    add_exit("east","/wizards/neophyte/forest/field1");
            items = allocate(6);
                    items[0] = "trees";
                    items[1] = "Branches on the tree are moving in the wind";
                    items[2] = "path";
                    items[3] = "It is going in that hay field";
}
