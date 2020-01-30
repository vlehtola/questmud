inherit "room/room";

reset(arg) {
  if(arg) { return; }

 if(!present("guard")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre4"), this_object());
 }

  add_exit("south", "/wizards/torspo/areat/ogre/room12.c");
  add_exit("west", "/wizards/torspo/areat/ogre/room10.c");
  add_exit("enter", "/wizards/torspo/areat/ogre/house1.c");

   short_desc = "Training fields";
  long_desc = "A sturdy wooden house has been built in here. It's made of thick logs and\n"+
              "couple of planks. Some skulls and bones are decorating its walls, as mark\n"+
              "of the authority, the houses owner has. Small chimney, on the houses roof,\n"+
              "lets out small puffs of smoke. The smoke rises upwards towards the sky,\n"+
              "curving and soaring in the wind.\n";

  items = allocate(2);
  items[0] = "house";
  items[1] = "Wooden house, decorated with skulls and bones. On the houses roof can be seen a small chimney";
}
