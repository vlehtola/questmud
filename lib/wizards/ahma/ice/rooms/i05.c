inherit "room/room";
int i, h;

reset(arg) {
  add_exit("out", "312");
  short_desc = "A dark igloo made of frozen snow";
  long_desc = "This igloo seems to be particularly dim and feminine. The furs covering\n" +
              "the floor have been coloured in faint red. The walls are uncovered, but\n" +
              "some simple pictures has been drawn on them. The igloo's decoration with\n" +
              "table, bed-site, drawings and carving on the walls form a cosy entity,\n" +
              "and it is not a surprise if the igloo would be owned by a female Dwarf.\n";
  items = allocate(10);
  items[0] = "furs";
  items[1] = "The bear furs cover the igloo's floor thoroughly. The furs seem very\n" +
             "special due to their unusual colouring, pink. The originally white furs\n" +
             "have probably been coloured with small amount of red blood, making the\n" +
             "mixture look a bit pinkish. The furs lay a unique atmosphere over igloo";
  items[2] = "fur";
  items[3] = "Try looking at 'furs'";
  items[4] = "pictures";
  items[5] = "Simple pictures, such as animals, humanoids and trees, have been drawn\n" +
             "all around the igloo walls. The pictures are dark red of their colour.\n" +
             "The paintings emit a faint stench of blood";
  items[6] = "picture";
  items[7] = "Try looking at 'pictures'";
  items[8] = "table";
  items[9] = "A small wooden table is standing by the igloo's wall. Nothing out of\n" +
             "ordinary can be seen near the table or about it";
  if(!i) {
    if(!present("dooris")) {
      move_object(clone_object("/wizards/ahma/ice/mob/dwarf05"), this_object());
      if(h) { present("dooris")->disablequest(); }
    }
  }
}

nopop() {
  i = 1;
}

yespop() {
  i = 0;
  h = 1;
}