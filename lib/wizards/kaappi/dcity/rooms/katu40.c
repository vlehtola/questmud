inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("west", "katu39.c");
  add_exit("east", "katu41.c");
  add_exit("south", "bakery.c");
  add_exit("north", "ashop.c");
  
  short_desc = "The Mormain street";
  long_desc = ""
"###########       You are standing in front of an armour shop and bakery.\n"+
"#    V            The smell of freshly baked bread is overwhelming you.\n"+
"#  A |            In north you can see armourer currently making some\n"+
"#+-*-+-9-+-       mithril shield.\n"+ 
"#| B |     \n"+
"#|S W| ####\n";

  set_light(2);
}
