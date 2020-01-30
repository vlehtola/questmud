inherit "room/room";

reset(arg) {
  if(arg) { return; }

 if(!present("servant")) {

 move_object(clone_object("/wizards/torspo/areat/ogre/monsters/servant.c"), this_object()); move_object(clone_object("/wizards/torspo/areat/ogre/monsters/servant.c"), this_object());
 }
  add_exit("out", "/wizards/torspo/areat/ogre/room19.c");
  add_exit("east", "/wizards/torspo/areat/ogre/house2_03.c");
  add_exit("west", "/wizards/torspo/areat/ogre/house2_02.c");
  add_exit("north", "/wizards/torspo/areat/ogre/house2_04.c");

  short_desc = "house";
  long_desc = "This is the entrance of this marvelous and beautiful house. There\n"+
              "are a lot of paintings and decoratives around the room and some\n"+
              "colourful carpet covers the whole floor. Room separates into three\n"+
              "parts and to north can be seen some kind of throneroom.\n";
  items = allocate(6);
   items[0] = "paintings";
   items[1] = "Some colourful paintings of ogre king and his achievements";
   items[2] = "decoratives";
   items[3] = "Flags of the ogre nation. It has a white background and blue cross painted over it";
   items[4] = "carpet";
   items[5] = "A carpet made of love";
  set_not_out(1);
  set_light(3);
}
