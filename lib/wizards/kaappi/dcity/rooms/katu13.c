inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu7.c");
  add_exit("north", "katu21.c");
  add_exit("east", "house7.c");
  
  short_desc = "The Gimbar street";
  long_desc = ""
" | p |   |#     This is Gimbar street. You see several citizens walking\n"+
"-o---+-6-+#     in the street. There is a door leading to the east.\n"+
" |   | H |#     You can see the crossing of the streets in the north and\n"+   
"H4H  *H H|#     south. A stone lantern is hanging on the wall.\n"+  
" |   | H |#\n"+   
"-+---+---+#\n";

  set_light(2);
}
