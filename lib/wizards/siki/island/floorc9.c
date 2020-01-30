inherit "room/room";

object monster;
reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/slave1");
      move_object(monster, this_object());
      }
      if(arg) return;
   
  add_exit("east","/wizards/siki/island/floorc8");



  short_desc = "End of the abandoned mining tunnel";
  long_desc = "End of the dark and abandoned mining tunnel. The walls\n"+
              "are extremely hard at this point, it is impossible to mine\n"+
              "here. The walls are secured with large wooden bars.\n";

         



  set_not_out(1);
 

  items = allocate(4);
  items[0] = "bar";
  items[1] = "Large wooden bar used to secure the walls of the tunnel";
  items[2] = "bars";
  items[3] = "Large wooden bars used to secure the walls of the tunnel";


}
