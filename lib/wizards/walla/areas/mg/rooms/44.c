inherit "room/room";


reset(arg) {

  add_exit("north","34");
  add_exit("west","43");
  add_exit("northwest","33");
  add_exit("south","entrance");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead, but what draws your\n" +
"attention, is a grave on your right side with a burning flame next to it.\n";

  items = allocate(4);
  items[0] = "grave";
  items[1] = "'Here lies the unknown soldier, fallen in battle.'";
  items[2] = "fire";
  items[3] = "A small fire is burning next to the grave.";


}
