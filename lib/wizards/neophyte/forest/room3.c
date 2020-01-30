inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Walking on the path";
                long_desc = read_file("/wizards/neophyte/forest/pathdesc.c");
    add_exit("southwest","/wizards/neophyte/forest/room2");
    add_exit("southeast","/wizards/neophyte/forest/room4");
            items = allocate(6);
                    items[0] = "path";
                    items[1] = "The path is winding through the bushes in deeper to the forest";
                    items[2] = "trees";
                    items[3] = "They are growing next to the path";
}
