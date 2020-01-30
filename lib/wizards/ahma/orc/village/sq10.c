inherit "room/room";
object mob01, mob02, mob03, mob04, mob05;
int childnum;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/sq07");
  add_exit("east", "/wizards/ahma/orc/village/sq11");
  short_desc = "In southwestern corner of village square";
  long_desc = read_file("/wizards/ahma/orc/village/sqdesc");

  if(childnum < 4) { if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(childnum < 4) { if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(childnum < 4) { if(!mob05) { move_object(mob05 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
}

childdead() {
  childnum--;
}