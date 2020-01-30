inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/beggar.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("west","/wizards/jenny/gnael/huoneet/city39.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city57.c");

    short_desc = "You are walking on a street";
    long_desc = "You are walking on a street, ahead of you in west you\n"+
              "can see the main road of Gnael, and if you look even more further\n"+
              "west you can see the a big building standing calmly in the wind.\n"+
              "In east you see the mayor's house and in southwest there is\n"+
              "a massive looking mansion rising towards the sky. The citywall\n"+
              "and some trees are the only things you can see in north.\n";


        items = allocate(6);
        items[0] = "building";
        items[1] = "You can see a big stone made building in west";
        items[2] = "mansion";
        items[3] = "A huge mansion is rising towards the sky in southwest";
        items[4] = "house";
        items[5] = "The mayor's house is located just a bit east from here";

}
