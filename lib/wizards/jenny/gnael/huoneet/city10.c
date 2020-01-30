inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/beggar.c");
    move_object(monster, this_object());
   }
  if(arg) return;

        add_exit("west","/wizards/jenny/gnael/huoneet/city9.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city11.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street in the southwest part\n"+
              "of Gnael. A huge mansion is rising towards the sky\n"+
              "nearby and a big door leading to the mansion can be seen\n"+
              "in the east. A cosy looking house is located a bit southwest\n"+
              "from here and some beggars are whining money and food\n"+
              "from strangers nearby.\n";

        items = allocate(8);
        items[0] = "mansion";
        items[1] = "A huge mansion is rising towards the sky nearby";
        items[2] = "door";
        items[3] = "A big iron door can be seen in east";
        items[4] = "house";
        items[5] = "A cosy looking house is located a bit southwest from here";
        items[6] = "beggars";
        items[7] = "pathetic looking beggars are whining money and food nearby";
}
