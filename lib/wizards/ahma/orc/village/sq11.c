inherit "room/room";
object mob01, mob02, mob03, mob04, mob05;
int childnum;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/sq08");
  add_exit("south", "/wizards/ahma/orc/village/vil06");
  add_exit("west", "/wizards/ahma/orc/village/sq10");
  add_exit("east", "/wizards/ahma/orc/village/sq12");
  short_desc = "In southern part of village square";
  long_desc = read_file("/wizards/ahma/orc/village/sqdesc");

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/salesman01"), this_object()); }
  if(!mob02) { move_object(mob02 = clone_object("/wizards/ahma/orc/mob/salesman02"), this_object()); }
  if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/customer"), this_object()); }
  if(childnum < 1) { if(!mob05) { move_object(mob05 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
}

childdead() {
  childnum--;
}