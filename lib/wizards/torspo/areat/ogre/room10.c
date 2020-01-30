inherit "room/room";

reset(arg) {

 if(!present("ogre")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre1.c"), this_object()); 
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre1.c"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/ogre/room1.c");
  add_exit("south", "/wizards/torspo/areat/ogre/room11.c");
  add_exit("east", "/wizards/torspo/areat/ogre/room13.c");

  short_desc = "Training fields";
  long_desc = "All plants have been cut down here. The ground is covered with thick\n"+
              "layer of fine sand, perfect base for young ogres to train different kinds\n"+
              "of fighting technics. Also some humanoid looking wooden dummies are built\n"+
              "here for the trainers. The fortress lies to the north and the field extends\n"+
              "to south and to east. Some kind of building can be seen to east.\n";

  items = allocate(2);
  items[0] = "dummies";
  items[1] = "Some humanoid shaped wooden dummies. They are made to take hits from the\n"+
             "training ogres and are therefore very hard";
}
