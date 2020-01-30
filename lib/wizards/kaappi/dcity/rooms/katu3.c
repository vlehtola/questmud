inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("north", "katu11.c");
  add_exit("east", "katu4.c");
  add_exit("west", "katu2.c");

  short_desc = "The crossing";
  long_desc = ""
"#+---+---o-     You are standing at the crossing of Thrmo and Dalvur street.\n"+ 
"#| H |   |      Dalvur street continues far to the north. Some houses can\n"+   
"#|H H3  H4H     be seen at both sides of the road. \n"+  
"#| H |   | \n"+   
"#+---*-1-+-\n"+  
"#########E#\n";

  set_light(2);
}
