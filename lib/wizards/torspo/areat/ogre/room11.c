inherit "room/room";

reset(arg) {

 if(!present("warrior")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre2.c"), this_object());
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre2.c"), this_object());

 }

  if(arg) { return; }
  add_exit("north", "/wizards/torspo/areat/ogre/room10.c");
  add_exit("east", "/wizards/torspo/areat/ogre/room12.c");

   short_desc = "Training fields";
  long_desc = "This part of the field is for the training of more experienced ogre warriors.\n"+
              "The ground is flat and covered with sand here also. Ogres here are larger and\n"+
              "more muscular. Different kinds of broken weapons, mostly bludgeons, are\n"+
              "collected in a big pile beside the western fence.\n";
  items = allocate(2);
  items[0] = "pile";
  items[1] = "Lots of broken, low quality weapons are piled in a big heap";
}
