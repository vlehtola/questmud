inherit "room/room";

reset(arg) {

 if(!present("child")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/child1"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/gnomes/cave19.c");
  add_exit("southeast", "/wizards/torspo/areat/gnomes/cave15.c");

  set_not_out(1);
  set_light(2);
  short_desc = "gnomish city";
  long_desc = "The way to the east doesn't look so used. The ground is covered with\n"+
              "quite thick layer of dust and the tunnel gets smaller and smaller.\n"+
              "Seems like the gnomes tried to separate the tunnel into two different\n"+
              "parts but they, for some reason, never finished the project.\n";
}
