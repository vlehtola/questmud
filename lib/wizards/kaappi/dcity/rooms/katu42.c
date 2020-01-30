inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu41.c");
  add_exit("east", "katu43.c");
  
  short_desc = "The Mormain street";
  long_desc = ""
"###########       You are standing at the Mormain street. It is leading\n"+
"   V              to east and west. There are several lanterns lightening\n"+
" A |              the street.\n"+
"---+-*-+---       You can see the fence of the park in south.\n"+ 
" B |       \n"+
"S W| ##### \n";

  set_light(2);
}
