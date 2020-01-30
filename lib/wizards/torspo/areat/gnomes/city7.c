inherit "room/room";

reset(arg) {
 if(!present("dog")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/beast2"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/gnomes/city6.c");
  add_exit("south", "/wizards/torspo/areat/gnomes/city4.c");

  set_not_out(1);
  set_light(2);
  short_desc = "Gnomish city";
  long_desc = "This is the northwestern part of the city. Road continues its way to east\n"+
              "and south. Boring looking houses are standing on the both sides of the road.\n"+
              "Some plants have been set on the ground. They look scrubby but seem still\n"+
              "to carry fruits.\n";
  items = allocate(2);
  items[0] = "plants";
  items[1] = "Small trees and bushes are planted on ground. It's strange that they can\n"+
             "live on the bare rock";
}
