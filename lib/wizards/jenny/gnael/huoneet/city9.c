inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/lizu_beggar.c");
    move_object(monster, this_object());
   }
  if(arg) return;


        add_exit("west","/wizards/jenny/gnael/huoneet/city8.c");
        add_exit("east","/wizards/jenny/gnael/huoneet/city10.c");
        add_exit("house","/wizards/jenny/gnael/huoneet/house2.c");

  short_desc = "You are walking on a street";
  long_desc = "You are walking on a street in the southwest part\n"+
              "of Gnael. There is a very beatiful looking garden\n"+
              "behind iron bars in north. There is a huge mansion\n"+
              "rising towards the sky near the garden. A cosy looking\n"+
              "house is located south from here.\n";

        items = allocate(8);
        items[0] = "garden";
        items[1] = "Very beautiful looking garden can be seen in north";
        items[2] = "bars";
        items[3] = "Strong looking iron bars are protecting the garden";
        items[4] = "mansion";
        items[5] = "A huge mansion is rising towards the sky nearby";
        items[6] = "house";
        items[7] = "A cosy looking house is located south from here";
}
