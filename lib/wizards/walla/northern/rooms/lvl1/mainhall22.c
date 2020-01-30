inherit "room/room";
 
 
reset(arg) {
 
  add_exit("west","/wizards/walla/northern/rooms/lvl1/mainhall21");
  add_exit("northwest","/wizards/walla/northern/rooms/lvl1/mainhall11");
  add_exit("northeast","/wizards/walla/northern/rooms/lvl1/mainhall13");
  add_exit("east","/wizards/walla/northern/rooms/lvl1/mainhall23");
  add_exit("north","/wizards/walla/northern/rooms/lvl1/mainhall12");
  items = allocate(2);
  items[0] = "painting";
  items[1] = "A great painting, picturing the late Thvaldar";
  short_desc = "In a great hall inside the mountain";
  long_desc =
"The main hall in this mountain castle is dimly lit by a great amount of torches,\n" +
"that are flickering in the light draught that you can feel here. There are a multitude\n" +
"of pillars that support the rocky roof, some 50 feet over your head. The hall expands\n" +
"in all the directions, and it is hard to see any walls in this faintly lit area.\n" +
"You can see a great painting of a dwarf before you.\n";
 
 
}
