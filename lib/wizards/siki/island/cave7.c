inherit "room/room";


object monster,monster2;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/guard3");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/slave3");
      move_object(monster2, this_object());
      }
      if(arg) return;
  add_exit("down","/wizards/siki/island/floord1");
  add_exit("up","/wizards/siki/island/floorc6");


  set_not_out(1);


  short_desc = "A narrow shaft";
  long_desc = "A deep, dark shaft leading into the darkness. The walls of\n"+
              "the tunnel are secured with large wooden bars. The rusty\n"+
              "iron stairs makes it possible to go even deeper.\n";

  items = allocate(6);
  items[0] = "bar";
  items[1] = "Large wooden bar used to secure the walls of the tunnel";
  items[2] = "bars";
  items[3] = "Large wooden bars used to secure the walls of the tunnel";
  items[4] = "stairs";
  items[5] = "Rusty iron stairs leading to the darkness";

}
