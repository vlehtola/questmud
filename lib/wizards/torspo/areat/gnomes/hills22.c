inherit "room/room";

reset(arg) {
 if(!present("guard")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/guard2"), this_object());
}
 if(!present("hero")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/hero"), this_object());
}

  if(arg) { return; }
  add_exit("east", "/wizards/torspo/areat/gnomes/hills23.c");
  add_exit("west", "/wizards/torspo/areat/gnomes/hills21.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/hills24.c");
  short_desc = "Gnomish mountains";
  long_desc = "The small path starts climbing to the upper parts of the mountain. Small\n"+
              "wooden barricade has been built here by the gnomes to stop the raids of\n"+
              "the mountains' monsters. Some logs are piled beside the southern wall.\n"+
              "A huge guardfire lights the area and keeps the wild animals away.\n";
  items = allocate(6);
  items[0] = "fire";
  items[1] = "Gnomish guards light this fire when day starts to darken to night. The fire\n"+
             "should keep wild animals away";
  items[2] = "barricade";
  items[3] = "Simple wooden barricade. It blocks the entrance here from the north";
  items[4] = "logs";
  items[5] = "Small pile of logs. If the fire starts to burn out gnomes can quickly feed it "+
             "with these";
}
