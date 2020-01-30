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

  add_exit("west", "katu29.c");
  add_exit("east", "katu31.c");
  
  short_desc = "The Bolain street";
  long_desc = ""
"#| B |            You are standing in little Bolain street leading to east\n"+
"#|S W| ####       and west. There are dwarven citizens walking in street.\n"+
"#|   | #          Lanterns attached to wall are lightening the street.\n"+
"#+-*-+ # K \n"+ 
"#|   | #   \n"+
"#2  G| ##-#\n";

  set_light(2);
}
}
