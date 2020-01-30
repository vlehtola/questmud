inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("northwest","/wizards/jhary/room/dwarves/dwarf12");
  add_exit("south","/wizards/jhary/room/dwarves/general");
  short_desc = "At an east lane";
  long_desc = "This is one of the outer places of the cave. You walk \n"+
              "along the east wall and suddenly there is only one way left.\n"+
              "The alternative is to go south into the shop. Along the west \n"+
              "side there are some poor housings. This isn't the best \n"+
              "place to live, and a lot of rubble covers the dimly lighted \n"+
              "road. For a good deal go south. Otherwise you should leave \n"+
              "this uneasy place to the northwest.\n";
}
                                        
