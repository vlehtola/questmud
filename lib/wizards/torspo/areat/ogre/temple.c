inherit "room/room";

reset(arg) {

 if(!present("monk")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre8.c"), this_object()); 
 }
  if(arg) { return; }
  add_exit("out", "/wizards/torspo/areat/ogre/room23.c");

  short_desc = "Temple";
  long_desc = "Low chanting can be heard in this large hall. You doubt that ogres haven't\n"+
              "built this, but some other race with more creativity. This temple is devoted\n"+
              "to the ogres' goddess of battle. Ogres here look calm and controlled, just\n"+
              "like outside.\n";
}
