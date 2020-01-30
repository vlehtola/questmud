inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu21.c");
  add_exit("east", "g2b.c");
  add_exit("north", "katu32.c");
  
  short_desc = "The Gimbar street";
  long_desc = ""
"   # | H |#      This is the Gimbar street. You are standing in front of the\n"+
" K # +---+#      city guard barracks. The open door leads to the east, where\n"+
"   # |   |#      you can hear some loud shouts. There is a gorgeous looking\n"+
"#-## *G  7#      low fence in west. Over the fence you can see some children\n"+
" | p |   |#      playing in the park.\n"+
"-o---+-6-+#\n";

  set_light(2);
}
