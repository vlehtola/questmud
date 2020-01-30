inherit "room/room";
object mob,mob2;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }

  if(!mob2) {
  mob2 = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob2, this_object()); }
{
  if(arg) return;

  add_exit("south", "katu29.c");
  add_exit("east", "gshop.c");
  add_exit("north", "katu39.c");
  
  short_desc = "The Kilvim street";
  long_desc = ""
"#  A |            You are standing in the front of a general store. You can see\n"+
"#+---+-9-+-       few dwarves doing some business in the shop.\n"+
"#| B |            You notice that this is very popular place among citizens and\n"+ 
"#*S W| ####       travellers. This is a very crowded place and there are several\n"+ 
"#|   | #          stands.\n"+
"#+-8-+ # K \n";

  set_light(2);
}
}
