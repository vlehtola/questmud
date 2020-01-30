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

  add_exit("south", "katu28.c");
  add_exit("west", "katu33.c");
  add_exit("north", "katu38.c");
  
  short_desc = "The crossing";
  long_desc = ""
"     | H |#       You find yourself standing in the end of the Bolain street. \n"+
"#### |  H|#       This is the worst part of the city. You can see some hoodlums\n"+
"   # | H |#       hoodlums begging money. The streets are covered with filth\n"+
" K # +---*#       and are poorly maintained. The wall is sloping to the west in\n"+
"   # |   |#       height of 150 feet.\n"+
"#-## |G  7#\n";

  set_light(2);
}
}
