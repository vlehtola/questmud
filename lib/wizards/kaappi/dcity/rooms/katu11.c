inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu3.c");
  add_exit("north", "katu17.c");
  add_exit("west", "house4.c");
  
  short_desc = "The Dalvur street";
  long_desc = ""
"#|   | p |      Dalvur street continues to the north and south. A small\n"+
"#+---+---o-     open door is leading to the west. You notice a small\n"+ 
"#| H |   |      crack on the wall. A lantern is hanging on the wall.\n"+   
"#|H H*  H4H\n"+   
"#| H |   | \n"+   
"#+---+-1-+-\n"; 

  set_light(2);
}
