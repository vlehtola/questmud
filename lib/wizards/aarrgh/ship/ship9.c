inherit "room/room";
reset(arg)  {
add_exit("deck", "/wizards/aarrgh/ship/ship6");
short_desc = "In the captains cabinet";
long_desc = "You are now stading in the cabinet of the captain.\n"+ 
                      "This cabinet is full of captain's personal property\n"+
                      "You notice some old logbooks and some old wine\n"+
                      "bottles lying around the cabinet.\n";
set_light(1);
if(!present("captain")) {
move_object(clone_object("/wizards/aarrgh/ship/captain"), this_object());
}
}
