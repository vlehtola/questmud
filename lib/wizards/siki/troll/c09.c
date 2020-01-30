inherit "room/room";

object monster;
   reset(arg) {
     if(!monster) {
      monster = clone_object("/wizards/siki/troll/monsters/warrior");
      move_object(monster, this_object());
      }
      if(arg) return;

  add_exit("north","/wizards/siki/troll/c08");
  add_exit("east","/wizards/siki/troll/c02");
  add_exit("west","wizards/siki/troll/c10");

  short_desc = "Inside a troll camp";
  long_desc = "A clearing in the middle of the dense forest. The trees have been cut\n"+
              "reasently and there are huge stumps everywhere. A thick wooden fence\n"+
              "separates the camp from the dense forest.\n";
   items = allocate(4);

   items[0] = "stumps";
   items[1] = "Stumps of cut trees";
   items[2] = "fence";
   items[3] = "A strong and tall wooden fence";


}
