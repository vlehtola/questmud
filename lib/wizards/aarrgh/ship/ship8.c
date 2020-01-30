inherit "room/room";

reset(arg) {

add_exit("northeast", "/wizards/aarrgh/ship/ship4");
add_exit("southeast", "/wizards/aarrgh/ship/ship3");
short_desc = "On the deck";
long_desc = "You are now standing on the deck. This ship seems to be\n"+
"somekind of a small War Galleon. The deck is clean and well polished.\n"+
"There are some barrels left lying on the floor. You notice\n"+
"some sailors all around the ship.\n";

items = allocate(4);
items[0]= "barrels";
items[1] = "These barrels are empty";
if(!present("sailor")) {
move_object(clone_object("/wizards/aarrgh/ship/sailor2"), this_object());
}
}
