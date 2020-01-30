inherit "room/room";

reset(arg) {

 if(!present("monk")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre8.c"), this_object()); 
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre8.c"), this_object());
 }
  if(arg) { return; }
  add_exit("enter", "/wizards/torspo/areat/ogre/temple.c");
  add_exit("southwest", "/wizards/torspo/areat/ogre/room22.c");
  add_exit("northwest", "/wizards/torspo/areat/ogre/room18.c");

  short_desc = "Fortress";
  long_desc = "Many ogres clad in robes are watching as you pass by. They seem relaxed\n"+
              "and peaceful, unlike others of their kind. Houses here are just huge\n"+
              "rocks that are carved hollow. There seems to be little decoration in\n"+
              "them. A strange temple-like building is located here, and way there seems\n"+
              "to be used often.\n";
}
