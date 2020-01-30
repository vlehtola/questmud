inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("east", "katu34.c");
  add_exit("west", "katu32.c");
  add_exit("north", "house11.c");
  
  short_desc = "The Bolain street";
  long_desc = ""
"     | H |#       You find yourself standing in the middle of Bolain street.\n"+
"#### |  H|#       This is the worst part of the city. You can see some hoodlums\n"+ 
"   # | H |#       begging money from the travellers. The streets are covered\n"+
" K # +-*-+#       with filth. You can see that the walls and streets are\n"+ 
"   # |   |#       poorly maintained. The walls are full of large cracks.\n"+
"#-## |G  7#       In north you can see an entrance to a house.\n";

  set_light(2);
}
