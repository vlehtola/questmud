inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu32.c");
  add_exit("north", "katu45.c");
  
  short_desc = "The Gimbar street";
  long_desc = ""
"          #       You are standing in the middle of Gimbar street.\n"+
"-+---+---+#       Over the fence you can see a beutiful park of the city\n"+
"     | H |#       of Amaranthgard. On the right side of you, you notice\n"+
"#### *  H|#       solid rock wall. The street continues to north and south.\n"+ 
"   # | H |#       A stone lantern is attached to the wall giving light.\n"+
" K # +---+#\n";

  set_light(2);
}
