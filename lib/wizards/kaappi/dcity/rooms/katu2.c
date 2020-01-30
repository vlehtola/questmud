inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("north", "house1.c");
  add_exit("east", "katu3.c");
  add_exit("west", "katu1.c");

  short_desc = "The Thrmo street";
  long_desc = ""
"#+---+---o-     Thrmo street which continues to the west and east.There\n"+ 
"#| H |   |      is a open door to north which is leading in to a small house. \n"+ 
"#|H H3  H4H     This part of the city is calm and the houses around look\n"+   
"#| H |   |      quite new. A lantern post is giving light here.\n"+   
"#+-*-+-1-+-\n"+  
"#########E#\n";

  set_light(2);
}
}
