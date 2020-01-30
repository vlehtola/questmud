inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "On a grassy field";
    long_desc = "You are standing on a huge green grass field. The huge white tower rises\n"+ 
        "the sky in front your eyes. The dark clouds hides the top of the tower.\n";
    add_exit("north", "out: 100 151");
    add_exit("northeast", "out: 100 151");
    add_exit("enter", "wizards/irmeli/area4/ruum1.c");
}
