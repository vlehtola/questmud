inherit "/wizards/onarion/tower/library";

reset(arg) {
  add_exit("south","/wizards/onarion/tower/tower11");

  short_desc = "Library";
  long_desc = "This is the great library.\n";

  random_books();
}


