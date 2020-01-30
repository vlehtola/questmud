inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob, this_object()); }

{
  if(arg) return;

  add_exit("south", "katu35.c");
  add_exit("east", "katu40.c");
  
  short_desc = "The crossing";
  long_desc = ""
"###########       You are standing at the northwest corner of the city.\n"+
"#    V            This is the area that most of the trading is centered.\n"+
"#  A |            There are lots of dwarves wondering around. \n"+
"#*---+-9-+-       From the east you can smell freshly baked bread.\n"+
"#| B |            Kilvim street is leading to south and Mormain is leading\n"+
"#|S W| ####       to east.\n";

  set_light(2);
}
}
