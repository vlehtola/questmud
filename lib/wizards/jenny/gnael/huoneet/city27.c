inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/elf_noble.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("north","/wizards/jenny/gnael/huoneet/city28.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city23.c");
        add_exit("house","/wizards/jenny/gnael/huoneet/house4.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking in the southeast part of the city.\n"+
              "In west you can see the main road of the city of\n"+
              "Gnael, and behind the road you can see a huge mansion\n"+
              "rising towards the sky. A small house seems to be next to you\n"+
              "and in the far southeast corner you can see somekind of a\n"+
              "market place. The streets are full of people and the air\n"+
              "is somewhat dusty. A small gust of wind is waving leaves in\n"+
              "nearby tree. Even though everyone seems to be in a rush, the\n"+
              "city looks calm and peaceful.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in west";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "house";
        items[5] = "A cosy looking house is standing next to you";
        items[6] = "leaves";
        items[7] = "The wind is waving some leaves in the nearby trees";

}
