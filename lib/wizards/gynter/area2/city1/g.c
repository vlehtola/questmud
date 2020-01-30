inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/c");
  add_exit("east","/wizards/gynter/area2/city1/h");
  /* setting desc */
  short_desc = "Falcon road";
  long_desc = "This is the left wing of the falcon. It is the west end of the\n"+
              "great road goes through the city west to east. It is the only\n"+
              "road that hasn't been totally run down. But it isn't far behind,\n"+
              "litter is forming in the sides of the street.\n";

  items = allocate(2);
  items[0] = "litter";
  items[1] = "It's all kind of trash here.\n";
}
