inherit "room/room";
int h = random(3);
object mob;

reset(arg) {
  add_exit("up", "/wizards/ahma/orc/forest/house03");
  add_exit("north", "/wizards/ahma/orc/forest/sub04");
  add_exit("west", "/wizards/ahma/orc/forest/sub02");
  short_desc = "Entrance to an underground opening";
  long_desc = read_file("/wizards/ahma/orc/forest/subdesc") + 
             "The steep hill leads up from here.\n";

  if(!mob) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental01"), this_object()); }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental02"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental03"), this_object()); }
  }
}