inherit "room/room";

reset(arg) {
 if(!present("aristocrat")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/citizen2"), this_object());
 }
 if(!present("mayor")) {
move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/citizen3"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/gnomes/city4.c");

  set_not_out(1);
  set_light(2);
  short_desc = "Gnomish city";
  long_desc = "This is the town hall of the gnome city. The place where criminals are\n"+
              "judged and the place where the whole citys' decisions are made. Walls and\n"+
              "floor are clean rock and there are some statues placed around this room.\n";

  items = allocate(2);
  items[0] = "statues";
  items[1] = "Some granite statues. They look as real as living gnomes";
}
