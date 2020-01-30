inherit "room/room";

reset(arg) {

 if(!present("citizen")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/citizen1"), this_object());
 }

  if(arg) { return; }
  add_exit("north", "/wizards/torspo/areat/gnomes/cave19.c");
  add_exit("southeast", "/wizards/torspo/areat/gnomes/cave8.c");

  set_not_out(1);
  set_light(2);
  short_desc = "gnomish city";
  long_desc = "This seems to be the main tunnel to the caves and city. Walls are very\n"+
              "smooth and the tunnel is roomy. The ground surface has worn out\n"+
              "because the gnomish inhabitants have used this tunnel for centuries. There\n"+
              "are some holes in the ceiling, some fresh air floats in from there.\n"+
              "The southeastern path seems to lead to the colonized sections of this cave.\n";
  items = allocate(2);
  items[0] = "holes";
  items[1] = "Some small holes are made here for ventilation purposes";
}
