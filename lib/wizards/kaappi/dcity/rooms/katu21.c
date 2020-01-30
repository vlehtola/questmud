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

  add_exit("south", "katu13.c");
  add_exit("north", "katu27.c");
  add_exit("west", "katu20.c");
  add_exit("east", "katu22.c");
  
  short_desc = "The crossing";
  long_desc = ""
"   # |   |#     This is the crossing of Gimbar and Thrala street. There\n"+
"#-## |G  7#     can be seen some houses in the east and south. Far from\n"+
" | p |   |#     the west you can still hear some loud noises from\n"+
"-o---*-6-+#     central square. In the north you can see few guards\n"+
" |   | H |#     entering barracks.\n"+
"H4H  5H H|#\n";

  set_light(2);
}
}
