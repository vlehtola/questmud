inherit "room/room";
reset(arg)  {
add_exit("south", "/wizards/aarrgh/ship/ship3");
add_exit("east", "/wizards/aarrgh/ship/ship11");
add_exit("north", "/wizards/aarrgh/ship/ship4");
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
