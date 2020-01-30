inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("west", "katu3.c");
  add_exit("east", "katu5.c");

  short_desc = "The Thrmo street";
  long_desc = ""
"---+---o---     Thrmo street continues to the west and east. At the east you\n"+ 
" H |   |        can see the big gates of the city. A lantern is hanging on \n"+   
"H H3  H4H       the wall. The walls are smooth and there are no cracks on \n"+    
" H |   |        the walls. Some citizens are walking on the street.\n"+   
"---+-*-+---\n"+  
"#######E###\n";

  set_light(2);
}
}
