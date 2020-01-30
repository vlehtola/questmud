inherit "room/room";


reset(arg) {

  add_exit("northwest","/wizards/walla/northern/rooms/lvl1/mainhall12");
  add_exit("west","/wizards/walla/northern/rooms/lvl1/mainhall22");
  add_exit("north","/wizards/walla/northern/rooms/lvl1/mainhall13");
  items = allocate(2);
  items[0] = "fireplace";
  items[1] = "A huge fireplace, stacked with logs";
  short_desc = "In a great hall inside the mountain";
  long_desc =
"The main hall in this mountain castle is dimly lit by a great amount of torches,\n" +
"that are flickering in the light draught that you can feel here. There are a multitude\n" +
"of pillars that support the rocky roof, some 50 feet over your head. The hall expands\n" +
"in all the directions, and it is hard to see any walls in this faintly lit area.\n" +
"You can see a nice fireplace before you.\n";


}

