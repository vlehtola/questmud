inherit "room/room";

object monster,monster2;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/slave1");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/smallguard");
      move_object(monster2, this_object());
      }
      if(arg) return;

  add_exit("north","/wizards/siki/island/floord2");
  add_exit("south","/wizards/siki/island/floord5");

  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into north and south. The tunnel\n"+
              "leading into east has collapsed as it was not secured well enough.\n"+
              "Some bodyparts of the dead slaves can be seen under the huge rocks.\n";
      
             


  set_not_out(1);

  items = allocate(4);
  items[0] = "bodyparts";
  items[1] = "Bloody bodyparts of orc slaves";
  items[2] = "rocks";
  items[3] = "Huge rocks on the ground. The eastern tunnel has collapsed";


}
