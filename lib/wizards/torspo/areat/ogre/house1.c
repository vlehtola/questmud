inherit "room/room";

reset(arg) {
  if(arg) { return; }

 if(!present("master")) {
  move_object(clone_object("/wizards/torspo/areat/ogre/monsters/master.c"), this_object());
 }
  add_exit("out", "/wizards/torspo/areat/ogre/room13.c");

  short_desc = "house";
  long_desc = "The house looks quite comfortable inside. There is a huge fireplace made of\n"+
              "bricks in the north wall. Floor is covered with a bearskin pelt and there\n"+
              "are lots of different kind of decoratives on the walls, colourful shields and\n"+
              "several weapons of different types. A table is standing in the middle of the\n"+
              "room and there is a chair placed next to it.\n";
  items = allocate(12);
  items[0] = "fireplace";
  items[1] = "A huge fireplace made of red bricks. The fire in it warms and lights up the room";
  items[2] = "pelt";
  items[3] = "A pelt of a large grizzly bear.";
  items[4] = "decoratives";
  items[5] = "High quality equipment hanging on the walls. It's a pity you can't reach them :)";
  items[6] = "table";
  items[7] = "Round oaken table";
  items[8] = "chair";
  items[9] = "A chair made of tree stump";
}
