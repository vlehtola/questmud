inherit "room/room";

reset(arg) {
    if (arg) { return; }
    short_desc = "Entrance to the old mystical forest";
    long_desc = "A forest full of old, rotten and big trees, has been growing in here for ever.\n"+
                  "No one knows, what's inside the forest, but there are some rumours that the\n"+
                  "ents live in there. There are many rumours about ents, but how they look, what\n"+
                  "are they and how many is still left of them, is still a mystery for the\n"+
                  "adventurers. It's hard to separate the ents from the regular trees and\n"+
                  "it's impossible to know, how powerful are they.\n";

    add_exit("forest", "/wizards/irmeli/ent/forest1.c");
    add_exit("north", "out:");
    add_exit("south", "out:");
    add_exit("west", "out:");
    add_exit("east", "out:");
}
