inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf3");
  add_exit("west","/wizards/jhary/room/dwarves/dwarf5");
  add_exit("south","/wizards/jhary/room/dwarves/dwarf6");
  short_desc = "At a main circle";
  long_desc = "A small street leaves the circle to the west. Some \n"+
              "housings are lined along the west and follow the small \n"+
              "lane. Opposite in the east you can see the big church of \n"+
              "Thalahamisar. In front of the church wall somebody planted \n"+
              "a few solanum, which use it to grow higher. The lane \n"+
              "continues to the north and the south.\n";
}
                                        
