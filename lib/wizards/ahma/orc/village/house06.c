inherit "room/room";

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/vil18");
  short_desc = "In tent-looking simple dwelling";
  long_desc = "A weird-looking apartment. This house has been made of wood into a shape\n" + 
              "of a tent. It is way too tight and low to move in without extreme un-\n" + 
              "comfortability. A small wooden stool has been stuffed in one corner. The\n" +
              "floor is covered with grass to make it suitable base for sleeping. The\n" + 
              "stench of rotting grass also attracts many different insects into the\n" + 
              "apartment. Some clothes are hanging on the eastern wall.\n";

  items = allocate(4);
  items[0] = "clothes";
  items[1] = "A stenchy and torn pants and shirt are hanging on the western wall. Seems\n" + 
             "like they would belong to the owner of this house, but you cannot see him\n" + 
             "anywhere around. Just before turning your head away from the clothes you\n" + 
             "spot a wrinkled piece of paper attached on the wall next to the clothes.\n" + 
             "There seems to be something written on it";
  items[2] = "paper";
  items[3] = "Haaii! I wetn in svimmin' to th� moat. �e rigth bak\n\n" + 
             "'How stupid can an Orc be?', you think when letting go of the paper";

}
