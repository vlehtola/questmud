inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("south", "katu17.c");
  add_exit("north", "katu31.c");
  add_exit("west", "g2a.c");
  
  short_desc = "The Dalvur street";
  long_desc = ""
"#|   | #         This is the Dalvur street. You are standing in front\n"+
"#+-8-+ # K       of the city guard barracks. The open door leads to the\n"+
"#|   | #         west, where you can hear some loud shouts. There is a\n"+
"#|  G* ##-#      gorgeous looking low fence in east. Over the fence you\n"+
"#|   | p |       can see some children playing in the park.\n"+
"#+---+---o-\n";

  set_light(2);
}
