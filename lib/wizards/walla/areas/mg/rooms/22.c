inherit "room/room";


reset(arg) {

  add_exit("north","12");
  add_exit("west","21");
  add_exit("northwest","11");
  add_exit("southwest","31");
  add_exit("south","32");
  add_exit("northeast","13");
  add_exit("southeast","33");
  add_exit("east","23");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead. A large cross stands on\n" +
"your left side, and there is a plaque attached beneath it.\n";

  items = allocate(4);
  items[0] = "cross";
  items[1] = "A large cross, made out of granite.";
  items[2] = "plaque";
  items[3] = "'In memoriam: our beloved husband George.'";


}




