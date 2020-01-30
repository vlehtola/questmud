inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("northwest","/wizards/jhary/room/dwarves/dwarf6");
  add_exit("northeast","/wizards/jhary/room/dwarves/dwarf8");
  short_desc = "At a south lane";
  long_desc = "Here you are at the south-side of the church. It's \n"+
              "located to the north and the wall describes a half \n"+
              "circle. there are seven small windows, each lighted \n"+
              "with a candle in the wall. The main circle widens here \n"+
              "into a small square and a road to the mines turns south. \n"+
              "The entrance to the mines is closed at the moment. \n"+
              "West from here you can see the cave wall raising into the \n"+
              "darkness.Some shops and houses are situated to the east. \n"+
              "Instead of going into the mines you can walk further on \n"+
              "the circle to northeast or northwest.\n";
}
                                        
