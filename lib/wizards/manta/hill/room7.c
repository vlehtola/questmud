inherit "room/room";

reset(status arg) {
  if(!present("demon 2", this_object()))
    move_object(clone_object("/wizards/manta/castle/dem2.c"), this_object());
  if(arg) return;
  add_exit("south", "/wizards/manta/hill/room4");
  add_exit("north", "/wizards/ahma/castle/rooms/area01");
  short_desc = "A path to castle";
  long_desc = "This is small path leading to big abandoned castle ahead.\n";
}








