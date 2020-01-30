inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("south", "katu10.c");
  add_exit("north", "katu24.c");
  add_exit("east", "katu16.c");
  
  short_desc = "The crossing";
  long_desc = ""
"#|   | #        You are standing at the crossing of Kilvim and Thrala street.\n"+
"#2  G| ##-#     Kilvim street continues to the north and south, and Thrala\n"+
"#|   | p |      street begins to lead to the east. Far in the east you can\n"+
"#*---+---o-     see the central square of Amaranthgard. There is a lantern post\n"+
"#| H |   |      standing on the crossing, giving light.\n"+
"#|H H3  H4H\n";

  set_light(2);
}
}
