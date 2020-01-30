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

  add_exit("west", "katu44.c");
  add_exit("east", "katu46.c");
  add_exit("south", "katu37.c");
  
  short_desc = "The crossing";
  long_desc = ""
"###########       This is the crossing of Gimbar and Mormain street.\n"+
"          #       In the east you can see the slums of the city.\n"+
"          #       Gimbar street is leading to south and Mormain\n"+
"-+---*---+#       to east and west.\n"
"     | H |#\n"+
"#### |  H|#\n";

  set_light(2);
}
}
