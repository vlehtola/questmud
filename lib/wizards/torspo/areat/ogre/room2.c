inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/ogre/room3.c");
  add_exit("east", "/wizards/torspo/areat/ogre/room1.c");

  short_desc = "Edge of the forest";
  long_desc = "This is the edge of the dark forest. Something makes you feel like\n"+
              "it would be better if you fled from here. There are no sounds coming\n"+
              "from the forest but one could still notice some movement there. To\n"+
              "north is the unscalable wall of ogre fortress and to east is the gate\n"+
              "to fortress.\n";
  }
