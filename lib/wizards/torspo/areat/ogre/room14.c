inherit "room/room";

reset(arg) {

 if(!present("woman")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre5.c"), this_object());
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre5.c"), this_object());
 }

  if(arg) { return; }
  add_exit("south", "/wizards/torspo/areat/ogre/room1.c");
  add_exit("northwest", "/wizards/torspo/areat/ogre/room15.c");
  add_exit("northeast", "/wizards/torspo/areat/ogre/room20.c");

   short_desc = "Fortress";
  long_desc = "You have entered the ogre fortress. The crude language of ogres can be\n"+
              "heard everywhere. Some shopkeepers are trying to sell their stuff here\n"+
              "and it seems that guards patrol around here regularly. Here aren't any other\n"+
              "full-grown males here though. The buildings around this place are ugly and\n"+
              "the ground is muddy. The road splits here, and it leads to northeast and\n"+
              "to northwest.\n";
}
