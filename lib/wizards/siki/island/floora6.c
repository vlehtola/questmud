inherit "room/room";


object monster;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/slave3");
      move_object(monster, this_object());
      }
      if(arg) return;




  add_exit("west","/wizards/siki/island/floora5");
  add_exit("east","/wizards/siki/island/floora7");




  short_desc = "A mining tunnel";
  long_desc = "A dark mining tunnel leading into east and west. The\n"+
               "marks on the cold stone walls are quite new.\n"+
              "The walls are secured with large wooden bars.\n";
             


  set_not_out(1);

  items = allocate(6);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "bar";
  items[3] = "Large wooden bar used to secure the walls of the tunnel";
  items[4] = "bars";
  items[5] = "Large wooden bars used to secure the walls of the tunnel";


}
