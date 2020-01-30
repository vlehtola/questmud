inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob, this_object()); }

{
  if(arg) return;

  add_exit("west", "katu46.c");
  add_exit("south", "katu38.c");
  
  short_desc = "The crossing";
  long_desc = ""
"###########       You are standing in the northeast corner of the city.\n"+
"          #       There are huge bonfires lit. Some bums are\n"+
"          #       roasting corpses of rats around them.\n"+
"-+---+---*#       Pieces of broken lanterns are lying all around. \n"+ 
"     | H |#       There aren't unbroken lantern anywhere to be seen.\n"+
"#### |  H|#\n";

  set_light(2);
}
}
