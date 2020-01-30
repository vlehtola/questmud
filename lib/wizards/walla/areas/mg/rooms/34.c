inherit "room/room";


reset(arg) {

  add_exit("north","24");
  add_exit("west","33");
  add_exit("northwest","23");
  add_exit("southwest","43");
  add_exit("south","44");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead. A large cross stands on\n" +
"your left side, and there is a plaque attached beneath it.\n";

  items = allocate(4);
  items[0] = "cross";
  items[1] = "A large cross, made out of limestone.";
  items[2] = "plaque";
  items[3] = "'In memoriam: our beloved wife Hannah.'";


}

