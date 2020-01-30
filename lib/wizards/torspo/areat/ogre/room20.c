inherit "room/room";

reset(arg) {

 if(!present("berserk")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre6.c"), this_object());
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre6.c"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/ogre/room15.c");
  add_exit("southwest", "/wizards/torspo/areat/ogre/room14.c");
  add_exit("northwest", "/wizards/torspo/areat/ogre/room17.c");
  add_exit("northeast", "/wizards/torspo/areat/ogre/room18.c");
  add_exit("southeast", "/wizards/torspo/areat/ogre/room22.c");

   short_desc = "Fortress";
  long_desc = "A huge bonfire lights up this part of the area. It is probably used in\n"+
              "some strange ogre rituals. Ground is covered with blood drops and small\n"+
              "parts of raw meat and bone parts. Southwest from here is the gate to\n"+
              "fortress, and the road leading out is very crowded.\n";
  items = allocate(2);
  items[0] = "bonfire";
  items[1] = "This huge bonfire lights up a large area around it. One burned skeleton in\n"+
             "the fire";
}
