inherit "room/room";

reset(arg) {
add_exit("southwest", "/wizards/aarrgh/ship/ship8");
add_exit("east", "/wizards/aarrgh/ship/ship5");
add_exit("south", "/wizards/aarrgh/ship/ship10");
short_desc = "On the deck";
long_desc = "You are now standing on the deck. This ship seems to be\n"+
"somekind of a small War Galleon. The deck is clean and well polished.\n"+
"There are some barrels left lying on the floor. You notice\n"+
"some sailors all around the ship.\n";

items = allocate(4);
items[0]= "barrels";
items[1] = "These barrels are empty";
}
