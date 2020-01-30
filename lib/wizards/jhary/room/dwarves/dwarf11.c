inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("northwest","/wizards/jhary/room/dwarves/dwarf10");
  short_desc = "At a south lane";
  long_desc = "The favourite housing area of Thalahamisar is located \n"+
              "northwest from this point. Here, close to the wall, \n"+
              "nobody wanted to erect a house. The road is less lighted \n"+
              "with torches, and the way once keeps going on to the south. \n"+
              "This wasn't the main entrance of Thalahamisar, but some \n"+
              "smugglers a long time ago digged a connection to leave the \n"+
              "town. Now this connection broke in, but some more or less \n"+
              "obviously traces show that there are still smugglers that \n"+
              "try to reopen this exit.\n";
}
                                        
