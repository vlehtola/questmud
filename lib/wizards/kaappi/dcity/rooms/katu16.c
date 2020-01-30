inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "house9.c");
  add_exit("west", "katu15.c");
  add_exit("east", "katu17.c");
  
  short_desc = "The Thrala street";
  long_desc = ""
"#|   | #        This is Thrala street. There is an open wooden door on the\n"+
"#2  G| ##-#     southern wall. Far in the east is central square of this city.\n"+
"#|   | p |      some voices can be heard from there. This street continues to\n"+
"#+-*-+---o-     the east and west.\n"+
"#| H |   | \n"+   
"#|H H3  H4H\n";

  set_light(2);
}
