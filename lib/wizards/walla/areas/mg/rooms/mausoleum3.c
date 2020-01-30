inherit "room/room";
  int i;
reset(arg) {
  if(arg) return;
  i = 0;
  add_exit("out","/wizards/walla/areas/mg/rooms/43");
  short_desc = "In a mausoleum";
  long_desc =
"You stand in a cool and calm mausoleum. There are some windows here that\n" +
"depict an awesome battle with vivid colors. A single candle illuminates \n" +
"the room and you can see a large coffin with inscriptions standing on a\n"+
"pedestal. There is a banner that flows on the far wall. The banner says:\n"+
"'To all the children, taken too soon'.\n";
  items = allocate(4);
  items[0] = "coffin";
  items[1] = "A large coffin, made out of oak.";
  items[2] = "inscriptions";
  items[3] = "'Let it grow, let it blossom, let it flow.'";
}
init() {
  ::init();
  add_action("open", "open");
}
open(str) {
  if(i != 1 && str == "coffin") {
  write("You open the coffin.\n");
  say(this_player()->query_name()+" opens the coffin.\n");
  i=1;
  return 1;
}
        if(str == "coffin") {
                write("It's already open\n");
                return 1;
        }
return 1;
}

