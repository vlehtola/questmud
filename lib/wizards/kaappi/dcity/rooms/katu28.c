inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu23.c");
  add_exit("north", "katu34.c");
  
  short_desc = "The Bila street";
  long_desc = ""
"   # | H |#      You are standing in Bila street, that continues to the north\n"+
" K # +---+#      and south. At the left side you can see walls of barracks and\n"+
"   # |   |#      on the right you see wall rising to the height of 150 feet\n"+
"#-## |G  *#      until it slopes to west. A bright lantern lights your way.\n"+
" | p |   |#\n"+
"-o---+-6-+#\n";

  set_light(2);
}
