inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/h");
  /* setting desc */
  short_desc = "An armour shop";
  long_desc = "An armour shop. Not very tidy though, there are spiderwebs hanging\n"+
              "from the ceiling and dust all over the shop. On the desk\n"+
              "you see a sign.\n";

  items = allocate(8);
  items[0] = "sign";
  items[1] = "Maybe you should try to 'read' it?\n";
  items[2] = "spiderwebs";
  items[3] = "The spiderwebs is hanging down from the ceiling everywhere.\n";
  items[4] = "dust";
  items[5] = "There is dust everywhere. It lies on everything.\n";
  items[6] = "ceiling";
  items[7] = "The ceiling is covered with spiderwebs.\n";
}

init() {
  ::init();
  add_action("read","read");
}

read(str) {
  if(str != "sign") return;
  write("The shop has unfortunetly been forced to close due to the\n");
  write("war with Therheran. All armours have been confiscated by the king.\n");
  return 1;
}
