inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("west","/world/city/emerald3");
  short_desc = "Duranghom teleport room";
  long_desc =
"You are inside a room full of different kind of markings and many different\n"+
"coloured crystals are emiting light. You are standing on a white mark\n"+
"which seems to glow blue light every now and then. You have never seen\n"+
"places like this before. On the wall there is a small plaque\n";
  items = allocate(4);
  items[0] = "crystals";
  items[1] = "Crystals are somehow chancing their colour all the time";
  items[2] = "plaque";
  items[3] = "Teleport to city of Asgroth 500 bronze coins. Type: 'Ask teleport' for transportation.\n"+
             "Players under 60lvl it's for free!";
}
init() {
  ::init();
  add_action("ask", "ask");
}

ask(str) {
  if(str == "teleport") {
    if(this_player()->query_level() < 60) {
      write("As you say the word 'teleport' the mark under you starts shining and suddenly you are\n"+
      "travelling over the mountains and plains.\n");
      say(this_player()->query_name()+" is sucked in to the mark.\n");
      this_player()->move_player("XX#virtual /room/out/outmap 280 122");
      return 1;
    } else {
      int num;
      num = 500;
      if(this_player()->query_money(3) < num) {
        write("A void echoes: Sorry, but you don't have enough bronze coins.\n");
        return 1;
      }
      this_player()->reduce_money(num,3);
      write("As you say the word 'teleport' the mark under you starts shining and suddenly you are\n"+
      "travelling over the mountains and plains.\n");
      say(this_player()->query_name()+" is sucked in to the mark.\n");
      this_player()->move_player("XX#virtual /room/out/outmap 280 122");
      return 1;
    }
  }
  write("Ask teleport if you want to go to Asgroth.\n");
  return 1;
}

