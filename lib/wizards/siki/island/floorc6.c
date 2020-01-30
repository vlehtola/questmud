inherit "room/room";


object monster,monster2;
reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/slave3");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/guard3");
      move_object(monster2, this_object());
      }
      if(arg) return;
   
  add_exit("down","/wizards/siki/island/cave7");
  add_exit("north","/wizards/siki/island/floorc5");
  add_exit("east","/wizards/siki/island/floorc7");
  add_exit("south","/wizards/siki/island/floorc8");


  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into north and south. The\n"+
              "marks on the cold stone walls are quite new. An extremely\n"+
              "sharply lowering shaft begins at this place leading into the\n"+
              "darkness. The walls are secured with large wooden bars.\n";

         



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
