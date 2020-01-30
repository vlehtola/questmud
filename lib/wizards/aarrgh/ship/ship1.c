inherit "room/room";

reset(arg) {
add_exit("out", "/wizards/aarrgh/ship/dock");
add_exit("north", "/wizards/aarrgh/ship/ship11");
add_exit("west", "/wizards/aarrgh/ship/ship3");
add_exit("east", "/wizards/aarrgh/ship/ship2");
short_desc = "On the deck";
long_desc = "You are now standing on the deck. This ship seems to be\n"+
"somekind of a small War Galleon. The deck is clean and well polished.\n"+
"There are some barrels left lying on the floor. You notice\n"+
"some sailors all around the ship.\n";

items = allocate(4);
items[0]= "barrels";
items[1]= "These barrels are empty";
}
