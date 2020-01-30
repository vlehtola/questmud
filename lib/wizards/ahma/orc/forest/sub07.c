inherit "room/room";
int h = random(3);
object mob;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/forest/sub04");
  add_exit("west", "/wizards/ahma/orc/forest/sub08");
  add_exit("northwest", "/wizards/ahma/orc/forest/sub10");
  short_desc = "In an underground opening";
  long_desc = read_file("/wizards/ahma/orc/forest/subdesc") + "\n";

  if(!mob) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental01"), this_object()); }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental02"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental03"), this_object()); }
  }
}