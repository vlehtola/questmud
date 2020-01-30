inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/beggar.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("west","/wizards/jenny/gnael/huoneet/city49.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city53.c");

    short_desc = "You are walking on a street";
    long_desc = "You are walking on a street, ahead of you in east you\n"+
              "can see the main road of Gnael, and if you look even more further\n"+
              "east you can see the roof of mayor's house. In west you can see\n"+
              "a big building with a small wooden door and in south there is\n"+
              "a massive looking mansion rising towards the sky. The citywall\n"+
              "and some trees is the only thing you can see in north.\n";


        items = allocate(8);
        items[0] = "building";
        items[1] = "You can see a big stone made building in west";
        items[2] = "mansion";
        items[3] = "A huge mansion is rising towards the sky in south";
        items[4] = "roof";
        items[5] = "Far away in east you can see the roof of mayor's house";
        items[6] = "door";
        items[7] = "Only one small door in a big building like that, weird..";

}
