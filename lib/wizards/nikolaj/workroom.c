inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("dragons","/wizards/nikolaj/areas/forest/r1.c");
  add_exit("cs","/world/city/cs");
  short_desc = "A messy sight in a form of Niko's workroom";
  long_desc = "This should be a long desc, however you notice \n"
        "that it isn't so long after all.\n"
        "In the corner of the workroom, you notice a statue.\n";
  property = allocate(1);
  property[0] = "no_summon";

  items = allocate(4);
  items[0] = "statue";
  items[1] = "Statue looks like Nikolaj. There's seems to be something behind it";
  items[2] = "kalle";
  items[3] = "There was a Kalle hiding behind the statue";
}

init() {
  ::init(); /* don't forget this, if you use init() */
  add_action("strangle", "strangle");
}

strangle(str) {
  if(str == "kalle") {
    write("You take a good grab of Kalle's throat and STRANGLE!\n");
    return 1;
  }
  write("Strangle who?\n");
  return 1;
}
