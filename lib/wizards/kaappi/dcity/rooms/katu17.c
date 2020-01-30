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

  add_exit("south", "katu11.c");
  add_exit("west", "katu16.c");
  add_exit("east", "katu18.c");
  add_exit("north", "katu25.c");
  
  short_desc = "The crossing";
  long_desc = ""
"#|   | #        You are standing at the crossing of Dalvur and Thrala street. \n"+
"#2  G| ##-#     You can hear the voices from the central square located in\n"+
"#|   | p |      east. Dalvur street continues to the north and south and Thrala \n"+
"#+---*---o-     street to east and west. There are few lanterns standing in the \n"+
"#| H |   |      street. You see a broken lantern lying on the street.\n"+   
"#|H H3  H4H\n"; 

  set_light(2);
}
}
