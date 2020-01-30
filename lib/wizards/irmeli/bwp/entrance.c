inherit "room/room";



reset(arg) {

    if (arg) { return; }

    short_desc = "At the edge of a forest";

    long_desc = "You are standing at the edge of a forest. A small path begins from here,\n"+ 

                  "leading to the forest. The standing crop of this forest is old and\n"+

                  "decayed. The soil is quite fertile, but very contaminated. The bark\n"+

                  "of the trees is grey and hard as a rock.\n";

    add_exit("path", "wizards/irmeli/bwp/room1.c");

    add_exit("east", "out: 56 135");

    add_exit("west", "out: 56 135");

    add_exit("south", "out: 56 135");

    add_exit("north", "out: 56 135");

}

