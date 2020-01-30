inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "house10.c");
  add_exit("west", "katu21.c");
  add_exit("east", "katu23.c");
  
  short_desc = "The Thrala street";
  long_desc = ""
"   # |   |#      You are standing in the Thrala street. There is an open door\n"+
"#-## |G  7#      leading to south. Thrala street continues to east and west.\n"+
" | p |   |#      Some dwarven citizen are walking on the street. A lantern is\n"+
"-o---+-*-+#      hanging on the wall. There is a small crack on the northern\n"+
" |   | H |#      wall.\n"+   
"H4H  5H H|#\n"; 

  set_light(2);
}
