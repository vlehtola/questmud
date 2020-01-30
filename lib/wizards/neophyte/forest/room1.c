inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Entrance to the forest";
        long_desc = "You are in a entrance to the forest. A small path starts in here\n"+
                    "winding through the bushes and trees. Tall trees almost block\n"+
                    "the sky above you.\n";
    add_exit("south", "out: 60 88");
    add_exit("east","/wizards/neophyte/forest/room2");
            items = allocate(4);
                    items[0] = "path";
                    items[1] = "The path starts to go deeper in the forest";
                    items[2] = "trees";
                    items[3] = "They are so huge and tall that you can't see the sky above";
}
