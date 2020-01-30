inherit "room/room";

object mob, mob1;
reset(arg) {
  /* Applying mobs */
  if(!mob && !random(2)) {
    mob = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob, this_object());
  }
  if(!mob1 && !random(2)) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Ccity");
  add_exit("south","/wizards/gynter/darke/city/Orcity2");
  /* setting desc */
  short_desc = "The road to the old parts";
  long_desc = "The gods of the old has made it impossible for the\n"+
              "darkelfs to close down this part of the city.\n"+
              "It is evident that they have tried, everywhere there are\n"+
              "signs of battle.\n";
}
