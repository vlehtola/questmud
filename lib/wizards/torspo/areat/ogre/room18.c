inherit "room/room";

reset(arg) {

 if(!present("soldier")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre3.c"), this_object()); 
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre3.c"), this_object());
 }
  if(arg) { return; }
  add_exit("southeast", "/wizards/torspo/areat/ogre/room23.c");
  add_exit("southwest", "/wizards/torspo/areat/ogre/room20.c");
  add_exit("north", "/wizards/torspo/areat/ogre/room19.c");

  short_desc = "Fortress";
  long_desc = "The ground is dead and there are lots of different barrack-like\n"+
              "buildings all over the place. There are no civilians in sight anymore and\n"+
              "it seems like outsiders are not so welcome here. To the north can be seen the\n"+
              "biggest building in fortress, probably the home of ogres' leader.\n";
}
