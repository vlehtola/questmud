inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/ogre/room4.c");
  add_exit("southwest", "/wizards/torspo/areat/ogre/room5.c");
  add_exit("east", "/wizards/torspo/areat/ogre/room2.c");

  short_desc = "Dark forest";
  long_desc = "Tranquility surrounds you as you proceed deeper into the forest.\n"+
              "Here are some faint tracks of average sized creatures and a clearing can\n"+
              "be seen to the west. A narrow path starts wondering to the southwest.\n";
   }
