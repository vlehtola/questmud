inherit "room/room";

reset(arg) {
  object bread;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/o");
  /* setting desc */
  short_desc = "A bakery";
  long_desc = "A bakery. Not very tidy though, there are spiderwebs hanging\n"+
              "from the ceiling and old disgusting bread lying in the corners.\n"+
              "On the desk you see a sign.\n";

  items = allocate(4);
  items[0] = "sign";
  items[1] = "Maybe you should try to 'read' it";
  items[2] = "spiderweb";
  items[3] = "The spiderweb is big enough to be several months old";

  bread = clone_object("/wizards/gynter/area2/city1/eq/bread");
  move_object(bread, this_object());

}

init() {
  ::init();
  add_action("read","read");
}

read(str) {
  if(str != "sign") return;
  write("The shop has unfortunetly been forced to close due to the\n");
  write("war with Therheran. Owner gone to war.\n");
  return 1;
}
