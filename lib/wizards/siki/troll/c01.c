inherit "room/room";


   reset(arg) {
      if(arg) return;

  add_exit("north","/wizards/siki/troll/c04");
  add_exit("east","/wizards/siki/troll/c06");
  add_exit("south","/wizards/siki/troll/f16");
  add_exit("west","wizards/siki/troll/c02");

  short_desc = "Inside a troll camp";
  long_desc = "A clearing in the middle of the dense forest. The trees have been cut\n"+
              "reasently and there are huge stumps everywhere. In the thick wooden\n"+
              "fence is a hole, a gate to the forest.\n";

   items = allocate(10);

   items[0] = "hole";
    items[1] = "A hole in the fence allowing entrance to the camp";
   items[2] = "stumps";
   items[3] = "Stumps of cut trees";
   items[4] = "skulls";
   items[5] = "Bruised human skulls on the top of wooden sticks";
   items[6] = "fence";
   items[7] = "A strong and tall wooden fence";
   items[8] = "sticks";
   items[9] = "Wooden sticks in the fence with human skulls on the top of them";

         

}
