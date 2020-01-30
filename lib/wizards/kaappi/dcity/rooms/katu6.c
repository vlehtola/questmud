inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob, this_object()); }

{
  if(arg) return;

  add_exit("west", "katu5.c");
  add_exit("east", "katu7.c");

  short_desc = "The Thrmo street";
  long_desc = ""
"---o---+---     Thrmo street continues to the west and east. At west you\n"+ 
"   |   | H      can see big gates of the city. A lantern is hanging on \n"+   
"  H4H  5H H     the wall. The walls are smooth and there are no cracks on \n"+ 
"   |   | H      these walls.\n"+   
"---+-*-+---\n"+  
"###E#######\n";

  set_light(2);
}
}
