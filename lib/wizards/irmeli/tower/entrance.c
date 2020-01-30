inherit "room/room";

reset(arg) {

    if (arg) { return; }

    add_exit("north", "out: ");
    add_exit("south", "out: ");
    add_exit("west", "out: ");
    add_exit("east", "out: ");
    add_exit("gate", "wizards/irmeli/tower/room1.c");

    short_desc = "In front of massive white tower";
    long_desc = "You are standing on a huge green grass field. The huge white tower\n"+
                "rises\n"+
                "the sky in front your eyes. The dark clouds hides the top of the tower.\n";

    items = allocate(6);
    items[0] = "tower";
    items[1] = "A massive white tower has been built in the middle of green grassfield."+
               " It's made of big square stones, supported with thick boards and"+
               " strengthen with mortar. Despite all these structural things, the"+
               " tower is on a slant towards right";
    items[2] = "gate";
    items[3] = "A rusty gate, the only entrance to the tower, is open. Someone has"+
               " forced the lock open with might, therefore it's broken";
    items[4] = "lock";
    items[5] = "The broken lock is lying on the ground, next to the gate";

    set_water(0);
}
