inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/lizu_beggar.c");
    move_object(monster, this_object());
   }
  if(arg) return;

        add_exit("west","/wizards/jenny/gnael/huoneet/city11.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city13.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street in the southwest part\n"+
              "of Gnael. A huge mansion is rising towards the sky\n"+
              "next to you in west. In the east you can see the main\n"+
              "road of Gnael and some people are constantly running\n"+
              "and walking on it. A small gust of wind is waving the\n"+
              "branches nearby\n";

        items = allocate(4);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in front of you";
        items[2] = "branches";
        items[3] = "Wind is moving the branches calmly";
}
