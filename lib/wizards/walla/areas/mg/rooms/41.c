inherit "room/room";


reset(arg) {

  add_exit("north","31");
  add_exit("east","42");
  add_exit("northeast","32");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead, but what draws your\n" +
"attention, is a grave on your right side with a candle next to it.\n";

  items = allocate(4);
  items[0] = "grave";
  items[1] = "'Here lies Janis, sadly taken away from us.'";
  items[2] = "candle";
  items[3] = "A small candle has been lit at the side of the grave.";


}

