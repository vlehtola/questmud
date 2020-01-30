inherit "room/room";
reset(arg)  {
            add_exit("south", "/wizards/aarrgh/nyxi/volcano2");
            add_exit("west", "/wizards/aarrgh/nyxi/pool");
            add_exit("north", "/wizards/aarrgh/nyxi/volcano9");
            short_desc = "Hall of the Morfeus";
  long_desc = "An enormous hall with big marble pillars formed in line lies ahead. Screams\n"
              "of pain echo through the hall. The walls are painted with blood. Dust and\n"
              "ashes are gone. The floor is clean and reflects images of faces screaming in\n"
              "agony. The place is lit but you can't discover the source of the light. The\n"
              "presence of evil is very intense.\n";

items = allocate(4);
  items[0] = "floor";
  items[1] = "Reflecting images of screaming faces. Like they are trapped inside the floor";

set_light(1);
set_not_out(1);
  if(!present("priest"))  {
move_object(clone_object("/wizards/aarrgh/nyxi/mon/priest"),this_object());
  }
  if(!present("priest 2"))  {
move_object(clone_object("/wizards/aarrgh/nyxi/mon/priest"),this_object());
  }
}
