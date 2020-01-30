inherit "room/room";


object monster;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/slave2");
      move_object(monster, this_object());
      }

   
      if(arg) return;
  add_exit("north","/wizards/siki/island/floorb1");
  add_exit("down","/wizards/siki/island/cave6");
  




  short_desc = "End of the mining tunnel";
  long_desc = "An extremely sharply lowering shaft begins at this place leading\n"+
              "into the darkness. The marks on the cold stone walls are quite new.\n"+
              "The walls are secured with large wooden bars.\n";


  set_not_out(1);

  items = allocate(8);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "bar";
  items[3] = "Large wooden bar used to secure the walls of the tunnel";
  items[4] = "bars";
  items[5] = "Large wooden bars used to secure the walls of the tunnel";
  items[6] = "shaft";
  items[7] = "A long, dark shaft leading further into the darkness";

}
