inherit "room/room";

reset(arg) {
 if(!present("citizen")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/citizen1"), this_object());
 }
 if(!present("child") && random(5)) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/child1"), this_object());
 }
  if(arg) { return; }

  add_exit("east", "/wizards/torspo/areat/gnomes/city7.c");
  add_exit("south", "/wizards/torspo/areat/gnomes/city3.c");

  set_not_out(1);
  set_light(2);
  short_desc = "Gnomish city";
  long_desc = "This is the northwestern part of the city. Road continues its way to east\n"+
              "and south. Boring looking houses are standing on the both sides of the road.\n";
}
