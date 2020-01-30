inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob, this_object()); }

{
  if(arg) return;

  add_exit("north", "park21.c");
  add_exit("west", "katu19.c");
  add_exit("east", "katu21.c");
  
  short_desc = "The Thrala street";
  long_desc = ""
" #   # |        This is the Thrala street. There is a gorgeous looking low\n"+
" ##-## |G       fence in north. Over the fence you can see some children\n"+
" p | p |        playing in the park. There is gorgeus golden gate leading in\n"+
"---o-*-+-6-     to the park. The street is leading to east and west. From\n"+  
"   |   | H      central square in the west you can hear loud noises.\n"+   
"  H4H  5H H\n";

  set_light(2);
}
}
