inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "On the rocky, high hills";
    long_desc = "It has been gently climbing slope to this point, but from now on the uphill\n"+
                  "rises sharp, almost vertical. An dilapidated uphill road begins from here.\n"+
                  "The road goes uphill all the way to the top of the rocky, high hills.\n"+
                  "The top of the rocky, high hills is surrounded by the thick fog. It's\n"+
                  "impossible to say, how high the top reaches.\n";

    add_exit("road", "wizards/irmeli/gnomes/road1.c");
    add_exit("north", "out:");
    add_exit("west", "out:");
    add_exit("northwest", "out:");
}
