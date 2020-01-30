inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/beggar.c");
    move_object(monster, this_object());
   }
  if(arg) return;

        add_exit("house","/wizards/jenny/gnael/huoneet/house1.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/city2.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city4.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street in the southwest part\n"+
              "of Gnael. There is a cosy looking house west from\n"+
              "you and some kids are peeking from the window in\n"+
              "the second floor of the house. A few empty bottles of\n"+
              "liquor are laying on the ground and a huge mansion\n"+
              "is rising towards the sky nearby.\n";

        items = allocate(8);
        items[0] = "house";
        items[1] = "A cosy looking house is located west from you";
        items[2] = "kids";
        items[3] = "Some kids are giggling in the house";
        items[4] = "bottles";
        items[5] = "Some empty liquor bottles";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky nearby";
}
