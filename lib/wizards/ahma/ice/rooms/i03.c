inherit "room/room";

reset(arg) {
  add_exit("out", "208");
  short_desc = "A carefully-made igloo";
  long_desc = "Igloo looks even more beautiful from inside than it did from outside. The\n" +
              "pieces, from which it has been made of, are carved and attached to each\n" +
              "other with extreme precision. Regardless of igloo's fine outlook, the\n" +
              "air inside it feels very chilly. The ground is covered with thick, white\n" +
              "furs. On the northern wall is hanging another white fur, otherwise the\n" +
              "walls and the ceiling are bald. No furniture can be seen in the igloo at\n" +
              "all. A doorway is leading to south.\n";
  items = allocate(4);
  items[0] = "fur";
  items[1] = "Try looking at 'furs'";
  items[2] = "furs";
  items[3] = "In whole, the igloo has been decorated with four big, white furs. Because of\n" +
             "their big size, the furs must be of some adult polar bears'. Three of the\n" +
             "furs are covering the bottom of the igloo, and one, a bit bigger than its\n" +
             "kins, is hanging from the northern wall. The furs look very warm";

  if(!present("dwarf")) move_object(clone_object("/wizards/ahma/ice/mob/dwarf03"), this_object());
}
