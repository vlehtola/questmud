inherit "room/room";


reset(arg) {

  add_exit("west","42");
  add_exit("northeast","34");
  add_exit("northwest","32");
  add_exit("north","33");
  add_exit("enter","mausoleum3");
  add_exit("east","44");
  short_desc = "In the graveyard";
  long_desc =
"The graveyard seems quite quiet. You can hear some birds singing in the\n" +
"distance, and your own steps on the gravel road that meanders around the\n" +
"graves. You can see more graves lying up ahead. A large mausoleum stands\n" +
"here, apparently built for someone of great wealth and importance. A\n"+
"small plaque has been attached on the wall next to the mausoleum entrance.\n";

  items = allocate(4);
  items[0] = "mausoleum";
  items[1] = "A mausoleum, built for an important person.";
  items[2] = "plaque";
  items[3] = "'Built by the people, for the people.'";


}
