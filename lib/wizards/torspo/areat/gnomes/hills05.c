inherit "room/room";

reset(arg) {
 if(!present("farmer")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/farmer1"), this_object());
 }
 if(!present("child")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/child1"), this_object());
 }
  if(arg) { return; }
  add_exit("north", "/wizards/torspo/areat/gnomes/hills12.c");
  add_exit("east", "/wizards/torspo/areat/gnomes/hills06.c");
  short_desc = "Gnomish fields";
  long_desc = "The fields just continue. On the west side rises up some higher and\n"+
              "even more rocky hills which don't grow even grass. No path leads up there\n"+
              "and it's impossible to climb up. The air gets colder and you are thankful\n"+
              "for the protection the hills give against the strong, chilly wind.\n";
}
