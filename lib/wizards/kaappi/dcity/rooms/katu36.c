inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu31.c");
  add_exit("west", "wshop.c");
  add_exit("north", "katu41.c");
  
  short_desc = "The Dalvur street";
  long_desc = ""
"#  A |            You are standing in the front of a weapon shop. You can see\n"+
"#+---+-9-+-       few dwarves doing some business in the shop.\n"+
"#| B |            You notice that this is very popular place among citizens and\n"+ 
"#|S W* ####       travellers. This is a very crowded place and there are several\n"+
"#|   | #          stands.\n"+
"#+-8-+ # K \n";

  set_light(2);
}
