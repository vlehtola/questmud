inherit "room/room";

reset(arg) {

 if(!present("citizen")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/citizen1"), this_object());
 }

  if(arg) { return; }
  add_exit("northwest", "/wizards/torspo/areat/gnomes/cave20.c");
  set_not_out(1);
  set_light(1);
  short_desc = "gnomish caves";
  long_desc = "The corridor ends here. Eastern wall has been mauled a bit but seems like\n"+
              "the caving project has been stopped. Some hard wooden pillars held the\n"+
              "ceiling still and there are some rusty equipments lying on the ground.\n"+
              "Broken sign is leaning against the wall.\n";
  items = allocate(4);
  items[0] = "equipments";
  items[1] = "Rusty, mostly broken, pickaxes and hammer are lying on the ground. They\n"+
             "have been probably left here by the gnomish miners who worked here before";
  items[2] = "sign";
  items[3] = "Broken wooden sign. It has a picture of working men painted in it";
}
