inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/hobbit_noble.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("north","/wizards/jenny/gnael/huoneet/city17.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city22.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city15.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on the main street of the city of\n"+
              "Gnael. There is a crossing here that leads east\n"+
              "where you can see a few shops and houses. A huge\n"+
              "mansion is rising towards the sky in west. Many\n"+
              "people are coming and going from everywhere all\n"+
              "the time and everyone seems to be the most\n"+
              "important person in the city, atleast they\n"+
              "act like it would be true.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in front of you";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "shops";
        items[5] = "You can see three shops in east";
        items[6] = "houses";
        items[7] = "A few normal looking houses can be seen in east";
}
