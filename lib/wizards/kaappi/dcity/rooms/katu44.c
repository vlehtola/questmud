inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu43.c");
  add_exit("east", "katu45.c");
  
  short_desc = "The Mormain street";
  long_desc = ""
"###########       You are standing at the Mormain street. It is leading\n"+
"                  to east and west. There are few lanterns that are \n"+
"                  glowing dimly.\n"+
"-9-+-*-+---       You can see the fence of the park in south.\n"+
"       | H \n"+
" ##### |  H\n";

  set_light(2);
}
