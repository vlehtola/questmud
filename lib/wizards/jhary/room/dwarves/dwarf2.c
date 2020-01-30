inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("east","/wizards/jhary/room/dwarves/dwarf1");
  add_exit("west","/wizards/jhary/room/dwarves/dwarf3");
  add_exit("north","/wizards/jhary/room/dwarves/pub");
  add_exit("northeast","/wizards/jhary/room/dwarves/dwarf14");
  add_exit("southeast","/wizards/jhary/room/dwarves/dwarf9");
  add_exit("south","/wizards/jhary/room/dwarves/church1");
  short_desc = "At the western market place.";
  long_desc = "You step in front of the holy centre of Thalahamisar. The wide \n"+
              "open church door invites you to step in and pray to god. \n"+
              "The church stands alone, but north of the streets there are \n"+
              "some buildings. One of them is the 'real' centre of the town, \n"+
              "the PUB.\n"+
              "The place is well illuminated with torches, and you can see \n"+
              "that the street must either be often used or very old. \n"+
              "To the east you can walk onto the middle of the market place. \n"+
              "The main circle leads west and southeast. If you want to leave \n"+
              "the town, head directly northeast.\n"+
              "The sounds of the pub invite you to go north.\n";              
}
                                        
