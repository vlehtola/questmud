inherit "room/room";
reset(arg)  {
add_exit("east", "/wizards/aarrgh/ship/ship1");
add_exit("north", "/wizards/aarrgh/ship/ship10");
add_exit("northwest", "/wizards/aarrgh/ship/ship8");
short_desc = "On the deck";
long_desc = "You are standing on the deck of this small sized ship\n"+
  "The deck is clean and very well polished. You feel unsafe here.\n";
set_light(1);
if(!present("sailor"))  {
move_object(clone_object("/wizards/aarrgh/ship/sailor"), this_object());
}
if(!present("sailor 2"))  {
move_object(clone_object("/wizards/aarrgh/ship/sailor"), this_object());
}
} 
