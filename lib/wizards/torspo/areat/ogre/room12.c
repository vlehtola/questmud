inherit "room/room";

reset(arg) {

 if(!present("soldier")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre3.c"), this_object()); 
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre3.c"), this_object());
}

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/ogre/room11.c");
  add_exit("north", "/wizards/torspo/areat/ogre/room13.c");

   short_desc = "Training fields";
  long_desc = "The ground is flat and filled with fine sand. Some high quality weapons are\n"+
              "hanging from the weapon rack. Ogres here seem to be a lot more experienced\n"+
              "than in the other parts of the training area. To the west is the warrior\n"+
              "training area, and to north lies a building of some kind.\n";
  items = allocate(2);
  items[0] = "rack";
  items[1] = "Wooden rack helds some weapons on it";
}
