inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob, this_object()); }

{
  if(arg) return;

  add_exit("south", "katu19.c");
  add_exit("enter", "hall2.c");
  
  short_desc = "Entrance to the City hall";
  long_desc = ""
" | #   # |       You are standing in front of huge gates of city hall made of\n"+
"-+ # K # +-      pure mithril decorated with carvings of ancient dwarven heroes.\n"+
" | #   # |       On both sides of the gates you see wonderful statues of king\n"+
"G| ##*## |G      and queen of the dwarves, made of pure gold. If looked closely,\n"+
" | p | p |       one can read from pedestals of statues that these are beloved\n"+
"-+---o---+-      leaders of dwarven city of Amaranthgard.\n";

  set_light(2);
}
}
