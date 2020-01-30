inherit "room/room";

object monster;

   reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/troll/monsters/guard");
      move_object(monster, this_object());
      }

       if(arg) return;


  add_exit("north","/wizards/siki/troll/c01");
  add_exit("east","/wizards/siki/troll/f17");
  add_exit("south","/wizards/siki/troll/f04");
  add_exit("west","/wizards/siki/troll/f15");

  short_desc = "A small clearing";
  long_desc = "A small clearing in the middle of the dense forest. The\n"+
              "trees have been cut reasently and there are huge stumps\n"+
              "everywhere. In the thick wooden fence is a hole, a gate\n"+
              "to the troll camp.\n";

   items = allocate(10);

   items[0] = "hole";
   items[1] = "A hole in the fence allowing an entrance to the camp";
   items[2] = "stumps";
   items[3] = "Stumps of cut trees";
   items[4] = "skulls";
   items[5] = "Bruised human skulls on the top of wooden sticks";
   items[6] = "fence";
   items[7] = "A strong and tall wooden fence";
   items[8] = "sticks";
   items[9] = "Wooden sticks in the fence with human skulls on the top of them";

}

init() {
    ::init();
   add_action("north", "north");
}

north() {
      object ob,race;
      ob = present("guard", this_object());
      if (!ob) return 0;
      race = this_player()->query_race();
      if(race != "orc" && race != "troll" && race != "ogre") {
      tell_room(this_object(), "The troll guard stops "+this_player()->query_name()+" and grunts 'No "+this_player()->query_race()+" is allowed to enter.'\n");
      return 1;
      } else {
      tell_room(this_object(), "The troll guard smiles and grunts 'Ah! "+this_player()->query_race()+"s are always welcome to our camp.'\n");
      return 0;
      }
}
