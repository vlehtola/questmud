inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu14.c");
  add_exit("west", "katu22.c");
  add_exit("north", "katu28.c");
  
  short_desc = "The crossing";
  long_desc = ""
"   # |   |#      You are standing at the crossing of the Bila and Thrala stree.\n"+
"#-## |G  7#      Bila street continues to north and south, and Thrala street\n"+
" | p |   |#      begins to lead to the west. The wall is gently sloping to the\n"+
"-o---+---*#      west in the height of 150 feet. There is also a lanter post\n"+
" |   | H |#      standing on the crossing.\n"+   
"H4H  5H H|#\n"; 

  set_light(2);
}
