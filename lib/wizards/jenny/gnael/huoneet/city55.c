inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/melchior.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("south","/wizards/jenny/gnael/huoneet/city54.c");
        add_exit("enter","/wizards/jenny/gnael/huoneet/mayor1.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking in the northeast part of the city.\n"+
              "In south you can see the main road of the city of\n"+
              "Gnael, and behind the road you can see somekind of a\n"+
              "market place in the southeast part of the city. The mayor's\n"+
              "house is standing next to you in north. The streets are full\n"+
              "of people and the air is somewhat dusty. A small gust of wind\n"+
              "is waving leaves in nearby trees, even though everyone seems\n"+
              "to be in a rush, the city looks calm and peaceful.\n";

        items = allocate(8);
        items[0] = "house";
        items[1] = "The mayor's house is located next to you";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "market place";
        items[5] = "There are few shops in south";
        items[6] = "leaves";
        items[7] = "The wind is waving some leaves in the nearby trees";

}
