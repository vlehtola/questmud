inherit "room/room";
object monster;
reset(arg) {

if(!present("ent")) {
    move_object(clone_object("/wizards/irmeli/ent/monsters/ent2.c"),
    this_object());

if(arg) return;
}
    short_desc = "Mystic forest of ents";
    long_desc = "The forest consist of old, unusual looking trees, which can only be found in\n"+
                  "this very forest. The trees must be older than one century, at least some of\n"+
                  "the trees are. Some of the trees are rotten, the others are diseased, for no\n"+
                  "particual reason. The difference between regular trees and the trees growing\n"+
                  "in this forest is, that the bark of the trees in here is moss-green, not brown\n"+
                  "as usual.\n"+
                  "A thick mist is swelling just above the ground.\n";

    add_exit("north", "/wizards/irmeli/ent/forest6.c");
    add_exit("west", "/wizards/irmeli/ent/forest1.c");
    add_exit("northwest", "/wizards/irmeli/ent/forest2.c");
}
