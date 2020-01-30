inherit "room/room";
  int i;
reset(arg) {
  if(arg) return;
  i = 0;
  add_exit("out","/wizards/walla/areas/mg/rooms/12");
  short_desc = "In a mausoleum";
  long_desc =
"You stand in a cool and calm mausoleum. There are some windows here that\n" +
"depict an awesome battle with vivid colors. A single candle illuminates \n" +
"the room and you can see a large coffin with inscriptions standing on a\n"+
"pedestal. There is a banner that flows on the far wall. The Banner says:\n"+
"'In remembrance to Norman the Slim'.\n";
  items = allocate(4);
  items[0] = "coffin";
  items[1] = "A large coffin, made out of oak.";
  items[2] = "inscriptions";
  items[3] = "'Don't let the big man get you down.'";
}
init() {
  ::init();
  add_action("open", "open");
}
open(str) {
  if(i != 1 && str == "coffin") {
  object wight;
  wight = clone_object("/wizards/walla/areas/mg/mobs/wight.c");
  write("You open the coffin, only to realize your mistake too late.\n");
  say(this_player()->query_name()+" opens the coffin and lets out a wight.\n");
   move_object(wight, this_object());
  i = 1;
  return 1;
}
        if(str == "coffin") {
                write("It's already open\n");
                return 1;
        }
return 1;
}
