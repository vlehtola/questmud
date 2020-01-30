inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area02");
  add_exit("south", "/wizards/manta/hill/room7");
  short_desc = "Entrance to the castle";
  long_desc = "At the entrance to the rundown castle, the castle of Lhavorak.\n" + 
              "As stepping upon the hallway it becomes certain that the creatures which\n" + 
              "roamed in the castle yard have found their way inside the castle, too.\n" + 
              "There are not so many corpses lying around as in the castle yard, but\n" + 
              "the stench of burnt flesh and bloodstains on the walls and floor indicate \n" + 
              "that there are casualties inside the castle walls, too.\n" + 
              "The hallway leads to the throne room and to the yard.\n";
  set_not_out();
}