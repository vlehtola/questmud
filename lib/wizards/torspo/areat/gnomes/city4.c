inherit "room/room";

reset(arg) {
 if(!present("aristocrat")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/citizen2"), this_object());
 }

  if(arg) { return; }
  add_exit("south", "/wizards/torspo/areat/gnomes/city2.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/city7.c");
  add_exit("east", "/wizards/torspo/areat/gnomes/city5.c");

  set_not_out(1);
  set_light(2);
  short_desc = "Gnomish city";
  long_desc = "Road continues to north and south here. Wider path separates\n"+
              "to the east where is located a huge stone building. Some flowers\n"+
              "are growing beside the street and there are much less those ugly small\n"+
              "houses around.\n"+
              "A sign is placed on the ground.\n"; 

  items = allocate(4);
  items[0] = "flowers";
  items[1] = "Beautiful flowers are growing beside the street";
  items[2] = "sign";
  items[3] = "Do NOT pick up flowers";
}
