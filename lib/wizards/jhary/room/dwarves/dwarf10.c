inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("west","/wizards/jhary/room/dwarves/dwarf8");
  add_exit("south","/wizards/jhary/room/dwarves/empty");
  add_exit("southeast","/wizards/jhary/room/dwarves/dwarf11");
  short_desc = "At a south lane";
  long_desc = "All around you there are many houses of people living in \n"+
              "Thalahamisar. Many used the near to the centre to erect \n"+
              "a building here. The whole place looks very tidy and \n"+
              "comfortable illuminated with oil lamps. You aren't sure, \n"+
              "if somebody invited you, but one house to the south has a \n"+
              "open door and you can step inside and have a look. Between \n"+
              "the houses the road goes on to the southeast and the west.\n";
}
                                        
