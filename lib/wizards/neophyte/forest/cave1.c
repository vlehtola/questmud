inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "A small cave";
        long_desc = read_file("/wizards/neophyte/forest/cavedesc.c");
    add_exit("north","/wizards/neophyte/forest/room4");
    add_exit("southwest","/wizards/neophyte/forest/cave2");
    add_exit("southeast","/wizards/neophyte/forest/cave3");
    set_not_out(2);
                items = allocate(3);
                            items[0] = "dripstones";
                            items[1] = "The dripstones have taken their shape after a decades water dripping from the ceiling";
}
