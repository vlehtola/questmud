inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/ogre_noble.c");
    move_object(monster, this_object());
   }
  if(arg) return;

        add_exit("north","/wizards/jenny/gnael/huoneet/city31_cs.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city17.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on the main street of the city of\n"+
              "Gnael. You can see the Central Square of the city\n"+
              "in north. In southwest there is a huge mansion rising\n"+
              "towards the sky. Many people are coming and going from\n"+
              "everywhere all the time and everyone seems to be\n"+
              "the most important person in the city, atleast they\n"+
              "act like it would be true.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in front of you";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";

}
