inherit "room/room";
reset(arg)  {
add_exit("east", "/wizards/aarrgh/ship/ship12");
add_exit("west", "/wizards/aarrgh/ship/ship10");
add_exit("mast", "/wizards/aarrgh/ship/mast");
add_exit("north", "/wizards/aarrgh/ship/ship5");
add_exit("south", "/wizards/aarrgh/ship/ship1");
short_desc = "On the deck";
long_desc = "You are now standing inside the ship. This ship seems to be\n"+
"somekind of a small War Galleon. The deck is clean and well polished.\n"+
"There are some barrels and ropes left lying on the floor. You notice\n"+
"some sailors all around the ship..\n";
set_light(1);
if(!present("sailor"))  {
move_object(clone_object("/wizards/aarrgh/ship/sailor"), this_object());
}
if(!present("sailor 2"))  {
move_object(clone_object("/wizards/aarrgh/ship/sailor"), this_object());
}
} 
