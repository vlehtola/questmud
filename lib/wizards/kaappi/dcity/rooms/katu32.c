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

  add_exit("east", "katu33.c");
  add_exit("south", "katu27.c");
  add_exit("north", "katu37.c");
  
  short_desc = "The crossing";
  long_desc = ""
"     | H |#       You are standing at the crossing of the Gimbar and Bolain\n"+
"#### |  H|#       street. The crossing is leading to north,south and east.\n"+ 
"   # | H |#       On the left side there is a fence between the park and road.\n"+
" K # *---+#       One huge lantern is lightening the whole street.\n"+
"   # |   |#\n"+
"#-## |G  7#\n";

  set_light(2);
}
}
