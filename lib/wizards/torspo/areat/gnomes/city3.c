inherit "room/room";

reset(arg) {
 if(!present("child")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/child1"), this_object());
 }

  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/gnomes/cave8.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/city6.c");
  add_exit("south", "/wizards/torspo/areat/gnomes/city1.c");

  set_not_out(1);
  set_light(2);
  short_desc = "Gnomish city";
  long_desc = "Thin rock street continues to north and south from here. On the\n"+
              "both sides of the street have been mined huge holes in the\n"+
              "rock and now they serve as houses of gnomish citizens.\n"+
              "Houses are gray, as granite always is, and look dull but\n"+
              "they seem to serve their residents quite well. The strange\n"+
              "shimmer lightens the whole city and it is also quite warm\n"+
              "down here. A huge split in the rock at the west wall leads to gnomish mines.\n";
              


}
