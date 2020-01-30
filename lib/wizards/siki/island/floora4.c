inherit "room/room";


object monster;

reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/island/monsters/slave2");
      move_object(monster, this_object());
      }
      if(arg) return;



  add_exit("west","/wizards/siki/island/floora3");




  short_desc = "End of the mining tunnel";
  long_desc = "A narrow end of the mining tunnel. There is some ore\n"+
              "on the walls. A set of tracks leads to the west and there\n"+
              "is a wagon at the end of them. The walls have some fresh\n"+
              "mining marks and they are secured with huge wooden bars.\n";


  set_not_out(1);

  items = allocate(12);
  items[0] = "marks";
  items[1] = "Marks of mining on the walls";
  items[2] = "tracks";
  items[3] = "A set of iron tracks used for ore wagons";
  items[4] = "wagon";
  items[5] = "Iron wagon half full of different kinds of ores";
  items[6] = "bar";
  items[7] = "Large wooden bar used to secure the walls of the tunnel";
  items[8] = "bars";
  items[9] = "Large wooden bars used to secure the walls of the tunnel";
  items[10] = "ore";
  items[11] = "Different kinds of ores on the walls";
}
