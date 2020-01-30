inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("south","/wizards/jhary/room/dwarves/dwarf1");
  add_exit("southwest","/wizards/jhary/room/dwarves/dwarf2");
  add_exit("southeast","/wizards/jhary/room/dwarves/dwarf12");
  add_exit("north","/wizards/jhary/room/dwarves/dwarf15");
  short_desc = "At the northern market place";
  long_desc = "Fewer buildings are lined up the north of the market-place\n"+
              "of Thalahamisar. Behind the last houses in the north, the\n"+
              "lane narrows until the walls are so close to each other,\n"+
              "that only few people can enter at once. It was digged \n"+
              "this way to make it difficult to attack the town. This is \n"+
              "also the only (official) way to leave or enter this cave.\n"+
              "Torches illuminate the place and their smoke raises straight\n"+
              "up into the cave. Southwards you look at the centre of \n"+
              "Thalahamisar.\n";
}
                                        
