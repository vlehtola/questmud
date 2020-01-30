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


  add_exit("north","/wizards/siki/island/floorc3");




  set_not_out(1);


  short_desc = "End of the mining tunnel";
  long_desc = "A narrow end of the mining tunnel. There is some ore\n"+
              "on the walls. A set of tracks leads to the north and there\n"+
              "is a wagon at the end of them. The walls have some fresh\n"+
              "mining marks and they are secured with large wooden bars.\n";

  items = allocate(12);
  items[0] = "bar";
  items[1] = "Large wooden bar used to secure the walls of the tunnel";
  items[2] = "bars";
  items[3] = "Large wooden bars used to secure the walls of the tunnel";
  items[4] = "marks";
  items[5] = "Marks of mining on the walls";
  items[6] = "tracks";
  items[7] = "A set of iron tracks used for ore wagons";
  items[8] = "wagon";
  items[9] = "Iron wagon almost full of different kinds of ores";
  items[10] = "ore";
  items[11] = "Different kinds of ores on the walls";

}
