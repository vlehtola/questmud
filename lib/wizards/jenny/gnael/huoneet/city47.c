inherit "room/room";
object monster;
reset(arg) {

        if (!present("bolodir")) {
         move_object("wizards/jenny/gnael/mosut/bolodir.c", this_object());
        }

        if(arg) return;

        add_exit("north","/wizards/jenny/gnael/huoneet/city48.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city35.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street, there is a small\n"+
              "crossing in south that leads into the main road\n"+
              "of Gnael. Somewhat ahead, you see a few shops\n"+
              "and a big building is located in northwest. Far\n"+
              "south you can see a huge mansion rising towards\n"+
              "the sky.\n";

        items = allocate(8);
        items[0] = "crossing";
        items[1] = "There is a crossing in south leading to several places";
        items[2] = "shops";
        items[3] = "You can see a few shops in north";
        items[4] = "building";
        items[5] = "A big building is standing in northwest";
        items[6] = "mansion";
        items[7] = "A huge mansion is rising towards the sky in south";

}
