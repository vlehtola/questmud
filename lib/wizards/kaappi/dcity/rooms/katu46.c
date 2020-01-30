inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu45.c");
  add_exit("east", "katu47.c");
  add_exit("south", "house13.c");
  
  short_desc = "The Mormain street";
  long_desc = ""
"###########       You are standing in the poorest parts of the city.\n"+
"          #       There is a broken wooden door leading to house in\n"+
"          #       south. There is an immovable body lying on the ground\n"+
"-+---+-*-+#       and some giant rats are gnawing her leg.\n"+ 
"     | H |#       There are broken lanterns all around the area.\n"+
"#### |  H|#\n";

  set_light(2);
}
