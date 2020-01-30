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
  add_exit("north","/wizards/gynter/darke/city/Orcity2");
  add_exit("south","/wizards/gynter/darke/city/Scity1");
  /* setting desc */
  short_desc = "The road to the old parts";
  long_desc = "The presence of the old gods are stronger here.\n"+
              "And here are also the biggest signs of destruction.\n";
}
