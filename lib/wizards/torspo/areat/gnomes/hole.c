inherit "room/room";

reset(arg) {
 if(!present("wolf")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/beast1"), this_object());
 }
 if(!present("cub")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/beast3"), this_object());
 }

  if(arg) { return; }
  add_exit("out", "/wizards/torspo/areat/gnomes/hills26.c");

  short_desc = "Mountains";
  long_desc = "The cold wind, rain and ice have created this hole in the rock. Its walls\n"+
              "are rough rock but they give perfect protection against this cold wind.\n"+
              "The hole now serves some animals as their home, small piles of excrement\n"+
               "and hair is lying on the ground.\n";
  items = allocate(4);
  items[0] = "excrement";
  items[1] = "Small piles of dried wolf shit";
  items[2] = "hair";
  items[3] = "Wolf hair make the floor much softer";
}
