inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/hobbit_noble.c");
    move_object(monster, this_object());
   }
  if(arg) return;

        add_exit("north","/wizards/jenny/gnael/huoneet/city38.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city31_cs.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on the main street of the city of\n"+
              "Gnael. You can see the Central Square of the city\n"+
              "in south. In west you can see a big building and\n"+
              "and some smaller buildings, there are also some shops\n"+
              "in the west part of the city. In east you can see the roof\n"+
              "of the mayor's house behind some smaller buildings.\n"+
              "Many people are coming and going from everywhere all\n"+
              "the time and everyone seems to be the most important\n"+
              "person in the city, atleast they act like it would be true.\n";

        items = allocate(8);
        items[0] = "building";
        items[1] = "A big building is standing in northwest part of the city";
        items[2] = "people";
        items[3] = "You see many kind of people, from elf nobles to ogre beggars";
        items[4] = "buildings";
        items[5] = "Some small buildings can be seen all over the city";
        items[6] = "roof";
        items[7] = "You can see the roof of the mayor's house in east";

}
