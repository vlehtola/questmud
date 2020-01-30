inherit "room/room";

reset(arg) {
  if(!present("farmer")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/farmer1"), this_object());
}
  if(!present("pony")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/pony1"), this_object());
}

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/gnomes/hills11.c");
  add_exit("south", "/wizards/torspo/areat/gnomes/hills05.c");
  short_desc = "Grassy hills";
  long_desc = "High rocky hills block the way to the south. The gnomes seem to do something\n"+
              "for it though. Lots of broken picks and shovels lie on the ground and a huge\n"+
              "part of the hill has disappeared somewhere. Northern areas are nothing but\n"+
              "some wide cornfields.\n";
  items = allocate(8);
  items[0] = "pick";
  items[1] = "Some broken tools lie on the ground. The icy rock must be hard to break";
  items[2] = "picks";
  items[3] = "Some broken tools lie on the ground. The icy rock must be hard to break";
  items[4] = "shovel";
  items[5] = "Some broken tools lie on the ground. The icy rock must be hard to break";
  items[6] = "shovels";
  items[7] = "Some broken tools lie on the ground. The icy rock must be hard to break";
}
