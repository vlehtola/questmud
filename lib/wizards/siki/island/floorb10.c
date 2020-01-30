inherit "room/room";


object monster,monster2,monster3;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/guard3");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/guard3");
      move_object(monster2, this_object());
      }
      if(arg) return;

      if(!monster3) {
      monster3 = clone_object("/wizards/siki/island/monsters/lypt");
      move_object(monster3, this_object());
      }




  add_exit("north","/wizards/siki/island/floorb9");





  short_desc = "The command room";
  long_desc = "A dusty room full of messy pieces of paper. A huge wooden table fills\n"+
              "almost the whole room. Small spiderwebs cover the corners and the air is\n"+
              "musty. Each wall has a torch in an iron handle lighting the room.\n";
         



  set_not_out(1);
  set_light(3);

  items = allocate(10);
  items[0] = "papers";
  items[1] = "Some old plans of the mines";
  items[2] = "paper";
  items[3] = "A plan to continue the mining even more deeper";
  items[4] = "spiderweb";
  items[5] = "A small spiderweb in the corner full of dead flies";
  items[6] = "torch";
  items[7] = "A torch burning warmly and bringing light to the darkness";
  items[8] = "handle";
  items[9] = "An iron handle holding the torch";

}
