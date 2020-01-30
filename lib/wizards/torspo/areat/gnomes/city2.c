inherit "room/room";

reset(arg) {
 if(!present("citizen")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/citizen1"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/gnomes/city1.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/city4.c");

  set_not_out(1);
  set_light(2);
  short_desc = "Gnomish city";
  long_desc = "This is the southeastern part of the city. Road continues its way to north\n"+
              "and west. Boring looking houses are standing on the both sides of the road.\n";
               

}
