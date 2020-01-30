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
  add_exit("north","/wizards/gynter/darke/city/Orcity1");
  add_exit("south","/wizards/gynter/darke/city/Orcity3");
  /* setting desc */
  short_desc = "The road to the old parts";
  long_desc = "Everywhere there are houses missing walls, ready to collapse\n"+
              "at any moment. There are shattered stones everywhere.\n"+
              "The battle here must have been awful.\n";
}
