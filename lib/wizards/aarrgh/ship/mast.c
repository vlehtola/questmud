inherit "room/room";
reset(arg)  {
add_exit("down", "/wizards/aarrgh/ship/ship11");
short_desc = "At the top of the mast";
long_desc = "You are now at the top of the mast. This place is very high\n"+
"and you feel like you want to go down. This is not the place for you.\n";
set_light(1);
if(!present("parrot")) {
move_object(clone_object("/wizards/aarrgh/ship/parrot"), this_object());
}
}
