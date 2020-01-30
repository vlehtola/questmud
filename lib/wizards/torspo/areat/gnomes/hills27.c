inherit "room/room";

reset(arg) {
  if(arg) { return; }
 if(!present("tundra wolf")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/beast4"), this_object());
 }

  add_exit("southwest", "/wizards/torspo/areat/gnomes/hills26.c");

  short_desc = "Mountains";
  long_desc = "This small pit is the nest of winter wolf, leader of mountains' wolf\n"+
              "herd. High walls rise on each direction and there is even some kind of roof\n"+
              "here, a huge stone blocked over the pit. Small slot in the rock goes to\n"+
              "southwest.\n";
  items = allocate(2);
  items[0] = "rock";
  items[1] = "The huge rock has probably fallen from the upper parts of the mountain and\n"+
             "stucked over this tight funnel";
}
