inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/dwarf_noble.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("west","/wizards/jenny/gnael/huoneet/city18.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/city32.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city16.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on the main street of the city of\n"+
              "Gnael. There is a crossing here that leads west\n"+
              "where you can see a huge mansion rising towards\n"+
              "the sky. Many people are coming and going from\n"+
              "everywhere all the time and everyone seems to be\n"+
              "the most important person in the city, atleast they\n"+
              "act like it would be true.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky in front of you";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
}
