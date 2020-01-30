inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("south", "katu15.c");
  add_exit("north", "katu29.c");
  
  short_desc = "The Kilvim street";
  long_desc = ""
"#|   | #         This is the Kilvim street. At the right side of you there is a \n"+
"#+-8-+ # K       quite big house, and on the left the wall rises\n"+
"#|   | #         straight up until it reaches the height of 150 feet\n"+
"#*  G| ##-#      when it turns gently sloping to the east.\n"+
"#|   | p | \n"+
"#+---+---o-\n";

  set_light(2);
}
}
