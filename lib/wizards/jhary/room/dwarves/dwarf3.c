inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("east","/wizards/jhary/room/dwarves/dwarf2");
  add_exit("north","/wizards/jhary/room/dwarves/healer");
  add_exit("south","/wizards/jhary/room/dwarves/dwarf4");
  short_desc = "At a main circle";
  long_desc = "At the western side of the circle there are several \n"+
              "housings along the lane. They are lined up and end all at \n"+
              "the road. No building has more than two floors. You aren't \n"+
              "sure if you can see the ceiling raising up behind them, but \n"+
              "you know the huge cave ends there. Although the road is well \n"+
              "illuminated with torches, you can't examine the surrounding \n"+
              "buildings closer. The only one you discern is the healer \n"+
              "northward. To the east the street widens and in the \n"+
              "south you walk further on the main circle. \n";
}
                                        
