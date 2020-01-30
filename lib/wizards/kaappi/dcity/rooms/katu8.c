inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu7.c");
  add_exit("east", "katu9.c");
  add_exit("north", "house2.c");

  short_desc = "The Thrmo street";
  long_desc = ""
"-o---+---+#     Eastern parts of Thrmo street. There is an open door which\n"+ 
" |   | H |#     is leading in to a house. A little mumble can be heard from\n"+
"H4H  5H H|#     the house. A lantern is hanging on the wall.\n"+ 
" |   | H |#\n"+   
"-+---+-*-+#\n"+  
"#E#########\n";

  set_light(2);
}
