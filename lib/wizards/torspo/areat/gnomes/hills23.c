inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("southeast", "/wizards/torspo/areat/gnomes/hills17.c");
  add_exit("west", "/wizards/torspo/areat/gnomes/hills22.c");
  short_desc = "Grassy hills";
  long_desc = "You are now on the mountains. It is very cold up here and the strong wind\n"+
              "makes you shiver. The rocky ground is covered with snow. There has been\n"+
              "a fight here recently, the snow is red of blood and some corpses of men\n"+
              "lie on the ground.\n";
  items = allocate(2);
  items[0] = "corpses";
  items[1] = "Some corpses of men. They have been ripped apart. Also one dead gnomish\n"+
             "soldier lies on the ground";
}
