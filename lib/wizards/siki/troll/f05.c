inherit "room/room";



   reset(arg) {

      if(arg) return;

      

  add_exit("north","/wizards/siki/troll/f17");
  add_exit("east","/wizards/siki/troll/f20");
  add_exit("south","/wizards/siki/troll/f06");
  add_exit("west","wizards/siki/troll/f04");

  short_desc = "Great forest";
  long_desc = "A deep and sinister forest. There are different types of trees\n"+
              "in very dense, old and new, living and dead ones. Visibility is\n"+
              "extremely low cause of the trees. The ground is covered with a\n"+
              "layer of bushes.\n";
         
   items = allocate(4);

   items[0] = "trees";
   items[1] = "Old and new, dead and living trees";
   items[2] = "bushes";
   items[3] = "Thick layers of bushes covering the whole ground making it hard to move";
}
