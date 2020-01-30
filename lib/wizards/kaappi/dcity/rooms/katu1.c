inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("north", "katu10.c");
  add_exit("east", "katu2.c");

  short_desc = "The crossing";
  long_desc = ""
"#+---+---o-     You are standing at the southwest corner of the city,\n"+ 
"#| H |   |      crossing of Thrmo and Kilvim street. There are couple\n"+   
"#|H H3  H4H     of houses in the north and east. Some citizen can be\n"+   
"#| H |   |      seen walking on the streets. There is also a lanternpost\n"+   
"#*---+-1-+-     standing at the crossing.\n"+  
"#########E#     \n";
  
  set_light(2);
}
}
