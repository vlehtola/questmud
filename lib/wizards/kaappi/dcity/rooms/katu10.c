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

  add_exit("south", "katu1.c");
  add_exit("north", "katu15.c");
  add_exit("east", "house3.c");
  
  short_desc = "The Kilvim street";
  long_desc = ""
"#|   | p |      Kilvim street continues to the north and south. A small\n"+
"#+---+---o-     open door is leading to the east. A smooth wall is west\n"+ 
"#| H |   |      side of you. The wall rises straight up until it reaches\n"+   
"#*H H3  H4H     the height of 150 feet when it turns gently sloping to the\n"+  
"#| H |   |      east.\n"+   
"#+---+-1-+-\n"; 

  set_light(2);
}
}
