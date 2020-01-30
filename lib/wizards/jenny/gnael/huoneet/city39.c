inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/gnome_noble.c");
    move_object(monster, this_object());
   }
  if(arg) return;

        add_exit("west","/wizards/jenny/gnael/huoneet/city53.c");
        add_exit("north","/wizards/jenny/gnael/huoneet/city40.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city56.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city38.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on the main street of the city of\n"+
              "Gnael. You have arrived to a crossing that leads\n"+
              "into four different directions. The central square\n"+
              "of the city of Gnael is located in south. In west you\n"+
              "can see a big building and some smaller buildings,\n"+
              "there are also some shops in west part of the city.\n"+
              "In east you can see the mayor's house behind some\n"+
              "smaller buildings. Many people are coming and going\n"+
              "from everywhere all the time and everyone seems to be\n"+
              "the most important person in the city, atleast they act\n"+
              "like it would be true.\n";

        items = allocate(8);
        items[0] = "building";
        items[1] = "A big building is standing in northwest part of the city";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "buildings";
        items[5] = "Some small buildings can be seen all over the city";
        items[6] = "house";
        items[7] = "You can see the mayor's house in east";

}
