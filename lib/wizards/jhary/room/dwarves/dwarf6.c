inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf4");
  add_exit("southeast","/wizards/jhary/room/dwarves/dwarf7");
  short_desc = "At a main circle";
  long_desc = "Under the soft light of the torches you walk on the main \n"+
              "circle of Thalahamisar. Small houses line up to the west \n"+
              "and the cave ends right behind of them and to the south. \n"+
              "East there is the ancient church raising high inside the \n"+
              "cave. The south end of the church is a half circle open to \n"+
              "the north and consist of rare white sandstone. The main \n"+
              "circle of Thalahamisar goes on southeast and north.\n";
}
                                        
