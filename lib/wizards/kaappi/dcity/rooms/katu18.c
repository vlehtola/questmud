inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("north", "park2.c");
  add_exit("west", "katu17.c");
  add_exit("east", "katu19.c");
  
  short_desc = "The Thrala street";
  long_desc = ""
"   | #   #      This is the Thrala street. There is a gorgeous looking low\n"+
"  G| ##-##      fence in north. Over the fence you can see some children playing\n"+
"   | p | p      in the park. There is a gorgeous golden gate leading in\n"+
"---+-*-o---     to the park. The street is leading to east and west.\n"+
" H |   |        from the central square in the east you can hear loud noises.\n"+
"H H3  H4H  \n";

  set_light(2);
}
