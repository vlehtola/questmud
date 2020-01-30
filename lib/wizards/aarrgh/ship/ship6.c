inherit "room/room";

reset(arg) {

add_exit("southeast", "/wizards/aarrgh/ship/ship7");
add_exit("west", "/wizards/aarrgh/ship/ship5");
add_exit("south", "/wizards/aarrgh/ship/ship12");
add_exit("doorway", "/wizards/aarrgh/ship/ship9");
short_desc = "On the deck";
long_desc = "You are now standing on the deck. This ship seems to be\n"+
"somekind of a small War Galleon. The deck is clean and well polished.\n"+
"There are some barrels left lying on the floor. You can smell the taste\n"+
"of old wine coming from below. There is a doorway leading down\n";

items = allocate(4);
items[0]= "barrels";
items[1] = "These barrels are empty";
}
