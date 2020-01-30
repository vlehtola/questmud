inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/human_noble.c");
    move_object(monster, this_object());
   }
  if(arg) return;



        add_exit("north","/wizards/jenny/gnael/huoneet/city13.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/gate4.c");
        add_exit("house","/wizards/jenny/gnael/huoneet/house3.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on the main street of the city of\n"+
              "Gnael. Many people are coming and going from\n"+
              "everywhere all the time and everyone seems to be the\n"+
              "most important person in the city, atleast they\n"+
              "act like it would be true. There is a small house\n"+
              "next to you in east and a huge open gate is in south.\n";

        items = allocate(6);
        items[0] = "house";
        items[1] = "A cosy looking small wooden house";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "gate";
        items[5] = "The south gate is leading outside the city";
}