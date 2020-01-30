inherit "room/room";




object monster,monster2;


   reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/slave3");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/slave3");
      move_object(monster2, this_object());
      }
      if(arg) return;


  add_exit("east","/wizards/siki/island/floorc2");
  add_exit("south","/wizards/siki/island/floorc4");



  set_not_out(1);


  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into south and east. The\n"+
              "marks on the cold stone walls are quite new. A set of\n"+
              "tracks fades into the south and east. The walls are secured\n"+
              "with large wooden bars.\n";

  items = allocate(8);
  items[0] = "bar";
  items[1] = "Large wooden bar used to secure the walls of the tunnel";
  items[2] = "bars";
  items[3] = "Large wooden bars used to secure the walls of the tunnel";
  items[4] = "marks";
  items[5] = "Marks of mining on the walls";
  items[6] = "tracks";
  items[7] = "A set of iron tracks used for ore wagons";
}
