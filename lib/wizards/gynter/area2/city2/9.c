inherit "room/room";
reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/0");
  add_exit("west","/wizards/gynter/area2/city2/8");
  add_exit("north","/wizards/gynter/area2/city2/2");
  /* setting desc */
  short_desc = "A main road";
  long_desc = "This is the main road of the village.\n"+
              "It is used by several people and is quite crowded by day.\n"+
              "But strangely there aren't so much as a scratch on the road.\n"+
              "Suddenly you realise that there is a lever on the wall next to you.\n";

  items = allocate(2);

  items[0] = "lever";
  items[1] = "As you examine the lever and the surrounding area closely you\nsee a hairfine line on the wall behind the lever. Maybe the lever opens it?";
}

init() {
  ::init();
  add_action("pull_lever","pull");
}

pull_lever(str) {
  if(str != "lever") return;
  if((this_player()->query_quests("Therheran, Pulled Lever One")) && (this_player()->query_quests("Therheran, Pulled Lever Two"))) {
    write("As you pull the lever the wall infront of you starts to shimmer with a\n");
    write("blinding light and suddenly it vanishes without a trace.\n");
    this_player()->set_quest("Therheran, Opened Holy center");
    add_exit("south","/wizards/gynter/area2/city2/v");
     return 1;
  } else {
    write("It seems like there is something more to do.\n");
    return;
  }
}
