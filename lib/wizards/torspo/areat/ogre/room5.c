inherit "room/room";

reset(arg) {
 if(!present("deer")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/deer.c"), this_object());
 }

  if(arg) { return; }
  add_exit("northeast", "/wizards/torspo/areat/ogre/room3.c");
  add_exit("southwest", "/wizards/torspo/areat/ogre/room6.c"); 
  add_exit("north", "/wizards/torspo/areat/ogre/room4.c");
  short_desc = "Dark forest";
  long_desc = "A path leading deeper in the thick forest. Bushes carrying red berries are\n"+
              "growing next to the path, lining the path. It seems, that someone has picked\n"+
              "most of the red berries from the bushes. Trees in the forest are huge and\n"+
              "old, maybe from the ancient period. A hut, built in the forest border,\n"+
              "rises from the clearing towards north from here.\n";

  items = allocate(2);
  items[0] = "bushes";
  items[1] = "These green bushes carries red berries, which you have never seen before.\n"+
             "They might be useful because most of the berries are picked away already\n"+
             "and the ground is full of ogre-sized footsteps";
}
