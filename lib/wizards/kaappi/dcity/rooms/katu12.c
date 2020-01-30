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

  add_exit("south", "katu5.c");
  add_exit("north", "katu19.c");
  add_exit("west", "house5.c");
  add_exit("east", "house6.c");
  
  short_desc = "The Thordim street";
  long_desc = ""
" | p | p |      You are standing in Thordim street. Houses in the area\n"+
"-+---o---+-     are fancier than most of the others in the city. There \n"+ 
" |   |   |      are open doors leading to east and west. The street is \n"+   
"H3  H*H  5H     well maintained compared to most of the city. There is \n"+ 
" |   |   |      great marble lantern that lights the whole street.\n"+   
"-+-1-+---+-\n";

  set_light(2);
}
}
