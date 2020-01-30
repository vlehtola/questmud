inherit "room/room";
  int i;
reset(arg) {
  if(arg) return;
  i = 0;
  add_exit("out","/wizards/walla/areas/mg/rooms/24");
  short_desc = "In a mausoleum";
  long_desc =
"You stand in a cool and calm mausoleum. There are some windows here that\n" +
"depict an awesome battle with vivid colors. A single candle illuminates \n" +
"the room and you can see a large coffin with inscriptions standing on a\n"+
"pedistal. There is a banner that flows on the far wall, that says: \n"+
"'To the hero never crowned, To the soldier not renouned'.\n";
  items = allocate(4);
  items[0] = "coffin";
  items[1] = "A large coffin, made out of oak";
  items[2] = "inscriptions";
  items[3] = "The songs have all been sung, the bells have all been rung.";
}
init() {
  ::init();
  add_action("open", "open");
}
open(str) {
  if(i != 1 && str == "coffin") {
  object banshee;
  banshee = clone_object("/wizards/walla/areas/mg/mobs/banshee.c");
  write("You open the coffin, only to realize your mistake too late.\n");
  say(this_player()->query_name()+" opens the coffin and lets out a banshee.\n");
   move_object(banshee, this_object());
  i = 1;
  return 1;
}
        if(str == "coffin") {
                write("It's already open\n");
                return 1;
        }
return 1;
}
