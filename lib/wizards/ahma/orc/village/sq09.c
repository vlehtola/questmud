inherit "room/room";
object mob01, mob02, mob03, mob04, mob05;
int childnum;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/sq06");
  add_exit("south", "/wizards/ahma/orc/village/sq12");
  add_exit("west", "/wizards/ahma/orc/village/sq08");
  short_desc = "In central part of village square";
  long_desc = read_file("/wizards/ahma/orc/village/sqdesc");

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/salesman02"), this_object()); }
  if(childnum < 2) { if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/customer"), this_object()); }
}

childdead() {
  childnum--;
}