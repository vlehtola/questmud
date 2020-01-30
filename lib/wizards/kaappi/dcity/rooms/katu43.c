inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("west", "katu42.c");
  add_exit("east", "katu44.c");
  
  short_desc = "The Mormain street";
  long_desc = ""
"###########       You are standing at the Mormain street. It is leading\n"+
" V                to east and west. There are some lanterns which are \n"+
" |                lightening the street.\n"+
"-+-9-*---+-       You can see the fence of the park in south.\n"+
" |       | \n"+
"W| ##### | \n";

  set_light(2);
}
}
