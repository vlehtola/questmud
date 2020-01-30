inherit "room/room";

reset(arg) {

 if(!present("noble")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre7.c"), this_object());
 }
  if(arg) { return; }
  add_exit("northwest", "/wizards/torspo/areat/ogre/room20.c");
  add_exit("northeast", "/wizards/torspo/areat/ogre/room23.c");

  short_desc = "Fortress";
  long_desc = "This part of the city is home for the ogres in higher position. Houses\n"+
              "are less ugly and they have some kinds of yards here. Some animals are\n"+
              "tied up in yards, and some are currently taken away to fill the empty\n"+
              "stomachs of warriors. Even the road is better, it is no longer muddy\n"+
              "and wet. Some of the houses seem to be made from clay, not sticks and\n"+
              "branches like the houses in the poor area.\n";
}
