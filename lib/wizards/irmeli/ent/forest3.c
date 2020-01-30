inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "Mystic forest of ents";
    long_desc = "The forest consist of old, unusual looking trees, which can only be found in\n"+
                  "this very forest. The trees must be older than one century, at least some of\n"+
                  "the trees are. Some of the trees are rotten, the others are diseased, for no\n"+
                  "particual reason. The difference between regular trees and the trees growing\n"+
                  "in this forest is, that the bark of the trees in here is moss-green, not brown\n"+
                  "as usual.\n"+
                  "A thick mist is swelling just above the ground.\n";

    add_exit("north", "/wizards/irmeli/ent/forest5.c");
    add_exit("east", "/wizards/irmeli/ent/forest1.c");
    add_exit("northeast", "/wizards/irmeli/ent/forest2.c");
}
