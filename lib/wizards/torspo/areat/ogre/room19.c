inherit "room/room";

reset(arg) {

 if(!present("guard")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre4.c"), this_object()); 
 }
  if(arg) { return; }
  add_exit("enter", "/wizards/torspo/areat/ogre/house2_01.c");
  add_exit("south", "/wizards/torspo/areat/ogre/room18.c");
  short_desc = "Fortress";
   long_desc = "As you approach the large building in the back of the fortress, you notice\n"+
              "a small guard post on your way. There is something written above the\n"+
              "doorway but you don't manage to understand it. Unlike all the other\n"+
              "buildings, this building is made of black stone, maybe marble.\n"+
              "Some different sized bones are lying in the doorway.\n";
  items = allocate(4);
  items[0] = "post";
  items[1] = "If the guard post is occupied it is impossible to get in to the building";
  items[2] = "bones";
  items[3] = "A couple of bones lying on the ground";}
