inherit "room/room";

reset(arg) {

 if(!present("fisherman")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre9.c"), this_object());
 }
  if(arg) { return; }

  add_exit("south", "/wizards/torspo/areat/ogre/room5.c");
  add_exit("east",  "/wizards/torspo/areat/ogre/room3.c");
  add_exit("enter", "/wizards/torspo/areat/ogre/hut.c");
  short_desc = "clearing";
  long_desc = "This is some kind of a clearing deep in the middle of the woods. Hut made\n"+
              "of logs seems to be near the other side of the clearing. Some smoke\n"+
              "drifts out from a crude chimney. The paths lead deep in to dark forest.\n";
              "drifts out from a crude chimney. The paths lead deep in to dark forest.\n";
    }
