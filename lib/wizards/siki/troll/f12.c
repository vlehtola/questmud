inherit "room/room";

object monster,monster2;

   reset(arg) {
      if(!monster) {
      monster = clone_object("/wizards/siki/troll/monsters/advtroll");
      move_object(monster, this_object());
      }
      if(!monster2) {
      monster2 = clone_object("/wizards/siki/troll/monsters/huntroll");
      move_object(monster2, this_object());
      }
      if(arg) return;

      

  add_exit("east","/wizards/siki/troll/f13");
  add_exit("south","/wizards/siki/troll/f11");


  short_desc = "Great forest";
  long_desc = "A deep and sinister forest. There are different types of trees\n"+
              "in very dense, old and new, living and dead ones. Visibility is\n"+
              "extremely low cause of the trees. The ground is covered with a\n"+
              "layer of bushes. The forest ends in the north and there is a\n"+
              "thick fence made out of strong wood with human skulls on the\n"+
              "top of the sticks.\n";
         
   items = allocate(10);

   items[0] = "trees";
   items[1] = "Old and new, dead and living trees";
   items[2] = "bushes";
   items[3] = "Thick layers of bushes covering the whole ground making it hard to move";
   items[4] = "skulls";
   items[5] = "Bruised human skulls on the top of wooden sticks";
   items[6] = "fence";
   items[7] = "A strong and tall wooden fence";
   items[8] = "sticks";
   items[9] = "Wooden sticks in the fence with human skulls on the top of them";

}
