inherit "room/room";


object monster,monster2;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/guard3");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/slave1");
      move_object(monster2, this_object());
      }
      if(arg) return;




  add_exit("west","/wizards/siki/island/floora7");





  short_desc = "End of the mining tunnel";
  long_desc = "A narrow end of the mining tunnel. There is some ore on\n"+
              "the walls. The cold stone walls have some fresh mining\n"+
              "mark and they are secured with huge wooden bars.\n";
      
             


  set_not_out(1);

  items = allocate(8);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "bar";
  items[3] = "Large wooden bar used to secure the walls of the tunnel";
  items[4] = "bars";
  items[5] = "Large wooden bars used to secure the walls of the tunnel";
  items[6] = "ore";
  items[7] = "Different kinds of ores on the walls";

}
