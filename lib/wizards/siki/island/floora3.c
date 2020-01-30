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

  add_exit("east","/wizards/siki/island/floora4");
  add_exit("south","/wizards/siki/island/floora2");




  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into east and south. The\n"+
              "marks on the cold stone walls are quite new. A set of\n"+
              "tracks fades into the east and south.\n";


  set_not_out(1);

  items = allocate(4);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "tracks";
  items[3] = "A set of iron tracks used for ore wagons";
}
