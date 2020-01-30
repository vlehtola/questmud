inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/beggar.c");
    move_object(monster, this_object());
  }
  if(arg) return;


        add_exit("north","/wizards/jenny/gnael/huoneet/city5.c");
        add_exit("south","/wizards/jenny/gnael/huoneet/city8.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street in the southwest part\n"+
              "of Gnael. There is a very beatiful looking garden\n"+
              "behind iron bars in the east. There is a huge mansion\n"+
              "rising towards the sky behind the garden. Some birds are\n"+
              "flying over the garden and the air smells great.\n";

        items = allocate(8);
        items[0] = "garden";
        items[1] = "Very beautiful looking garden can be seen in east";
        items[2] = "bars";
        items[3] = "Strong looking iron bars are protecting the garden";
        items[4] = "mansion";
        items[5] = "A huge mansion is rising towards the sky nearby";
        items[6] = "birds";
        items[7] = "Some white pigeons are flying over the garden";
}
