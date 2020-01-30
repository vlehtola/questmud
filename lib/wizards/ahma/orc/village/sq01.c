inherit "room/room";
object mob01, mob02, mob03, mob04, mob05;
int childnum;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/sq04");
  add_exit("east", "/wizards/ahma/orc/village/sq02");
  short_desc = "In northwestern corner of village square";
  long_desc = read_file("/wizards/ahma/orc/sqdesc");

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/salesman01"), this_object()); }
  if(!mob02) { move_object(mob02 = clone_object("/wizards/ahma/orc/mob/salesman02"), this_object()); }
  if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/customer"), this_object()); }
  if(childnum < 2) { if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(childnum < 2) { if(!mob05) { move_object(mob05 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
}

childdead() {
  childnum--;
}