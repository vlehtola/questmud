inherit "room/room";


object monster,monster2;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/guard3");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/island/monsters/slave4");
      move_object(monster2, this_object());
      }
      if(arg) return;


  add_exit("north","/wizards/siki/island/floord9");
  add_exit("east","/wizards/siki/island/floord2");
  add_exit("west","/wizards/siki/island/floord8");

  





  short_desc = "A mining tunnel";
  long_desc = "A dark hall dividing the tunnel into three direction.\n"+
              "There is some ore on the walls and there are some fresh mining\n"+
              "mining marks. The cold walls are secured with huge wooden bars.\n";
      
             


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
