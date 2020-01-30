inherit "room/room";
int i;
reset(arg) {
  add_exit("out", "204");
  short_desc = "A crude igloo made of frozen snow";
  long_desc = "The walls and the ground are thoroughly covered with tiny skins of some\n" +
              "small animals. Due to the skins, the atmosphere inside the igloo is very\n" +
              "warm, almost hot. A small hole is located in the center of the ceiling.\n" +
              "Not much furniture can be seen around the room: a small, round table and\n" +
              "even smaller stool are located near the eastern wall. By the western wall\n" +
              "has been piled a huge pile of small pieces of animal hair, it must be the\n" +
              "the bed. A small doorway is leading out in north.\n";

  items = allocate(8);
  items[0] = "skins";
  items[1] = "You suspect there must be at least hundred skins hanging and lying all\n" +
             "around the walls and ceiling. The skins are very small, their previous\n" +
             "owners must have been quite weak animals, alike their hunter, too. The\n" +
             "skins are definitely worthless and taking them would be a waste of time";
  items[2] = "hole";
  items[3] = "The small hole's purpose in the ceiling is to refresh the igloo's air.\n" +
             "The hole leads the carbon dioxide gas out of the igloo, and sucks the\n" +
             "fresh tunnel air inside the igloo. The hole is small enough for not to\n" +
             "lower the temperature inside the igloo";
  items[4] = "table";
  items[5] = "The small wooden table seems to have more sentimental value than concrete\n" +
             "one. It has been tried to make round, but its shape is far from that. The\n" +
             "table is very small, alike the stool which is standing next to it";
  items[6] = "stool";
  items[7] = "A small wooden stool is standing by the eastern wall. The stool seems to\n" +
             "be crudely made, its legs seem to be somewhat different of length and size.\n" +
             "The stool is very small and ugly, but it must be good enough for the\n" +
             "person who tends to sit on it";
  
  if(!present("dwarf")) move_object(clone_object("/wizards/ahma/ice/mob/dwarf02"), this_object());
  if(i) present("dwarf")->specsay();
}

setspec() {
  i = 1;
}
