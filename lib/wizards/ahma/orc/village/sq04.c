inherit "room/room";
object mob01, mob02, mob03, mob04, mob05;
int childnum;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/sq07");
  add_exit("east", "/wizards/ahma/orc/village/sq05");
  add_exit("enter", "/wizards/ahma/orc/village/tent02");
  short_desc = "In northwestern of village square";
  long_desc = read_file("/wizards/ahma/orc/village/sqdesc") + 
              "A shabby-looking brown tent is standing here. A sign is hanging\n" + 
              "near the doorway to the tent\n";
  
  items = allocate(4);
  items[0] = "tent";
  items[1] = "A brown tent looks very old and much used. The tent is much lower than\n" + 
             "other tents seen in the square and it has some gaping holes in it. The\n" + 
             "holes seem to give lots of sentimental value to the tent. A wooden sign\n" + 
             "is hanging near the doorway into the tent";
  items[2] = "sign";
  items[3] = "Do you like valuable or antique stuff? You have come to the right place!\n" + 
             "Naglah's artifact shop offers you the most unbelievable items found in\n" + 
             "this corner of the world";

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/salesman01"), this_object()); }
  if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/salesman02"), this_object()); }
  if(!mob04) { move_object(mob04 = clone_object("/wizards/ahma/orc/mob/customer"), this_object()); }
  if(childnum < 1) { if(!mob05) { move_object(mob05 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
}

childdead() {
  childnum--;
}