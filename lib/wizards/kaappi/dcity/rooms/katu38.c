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

  add_exit("south", "katu34.c");
  add_exit("north", "katu47.c");
  add_exit("west", "house12.c");
  
  short_desc = "The Bila street";
  long_desc = ""
"          #       In the shady places of Bila street there are a lots of\n"+
"-+---+---+#       rats and beetles running around.\n"+
"     | H |#       On the left side you see a partially collapsed house.\n"+
"#### |  H*#       There are lots of broken stone lanterns around.\n"+  
"   # | H |#\n"+
" K # +---+#\n";

  set_light(2);
}
}
