inherit "room/room";


object monster,monster2;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/guard2");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/guard2");
      move_object(monster2, this_object());
      }
      if(arg) return;





  add_exit("south","/wizards/siki/island/floord2");





  short_desc = "A small guard post";
  long_desc = "A small guard post in an alcove of the tunnel. There is\n"+
              "a wooden table with two chairs in the northeastern corner.\n"+
              "A torch in an iron handle on the wall lights the room a bit.\n";



  set_not_out(1);
  set_light(2);

  items = allocate(12);
  items[0] = "table";
  items[1] = "A rotting wooden table. There are four dices on it.";
  items[2] = "chairs";
  items[3] = "Two old wooden chairs";
  items[4] = "chair";
  items[5] = "An old wooden chair. It is in a very bad condition.";
  items[6] = "torch";
  items[7] = "A torch burning warmly and bringing light to the darkness";
  items[8] = "handle";
  items[9] = "An iron handle on the western wall holding the torch";
  items[10] = "dices";
  items[11] = "Four wooden dices on the table. The guards have been playing"+
              "games for money";


}
