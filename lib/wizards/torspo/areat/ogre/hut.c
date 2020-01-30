inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("out", "/wizards/torspo/areat/ogre/room4.c");

  set_not_out(1);
  set_light(3);
  short_desc = "Wooden hut";
  long_desc = "This seems to be some fishers' hut. There are lots of different looking\n"+
              "fishing rods piled in one corner of the room. Western wall is covered with\n"+
              "fishing nets and there are lots of fish scales on the floor.\n";
  items = allocate(7);
  items[0] = "rods";
  items[1] = "A big heap of fishing rods";
  items[2] = "net";
  items[3] = "Hard and thick net. It is made to catch huge amount of fishes at the same time";
  items[4] = "scales";
  items[5] = "The caught fishes have been cleaned and the scales have fallen to the floor";
}
