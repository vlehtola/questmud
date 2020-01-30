inherit "room/room";

object mob, mob1;
reset(arg) {
  /* Applying mobs */
  if(!mob && !random(3)) {
    mob = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob, this_object());
  }
  if(!mob1 && !random(3)) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/citizen");
    move_object(mob1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/darke/city/Rcity7");
  add_exit("west","/wizards/gynter/darke/city/Rcity5");
  /* setting desc */
  short_desc = "The central city walk";
  long_desc = "As the new became the old and the old withered and dissapeared\n"+
              "as dust in the wind. A new city arose from the old, ontop of the old,\n"+
              "taking away all from the old. This road is lying here as a memory to all\n"+
              "that is old and to divide what is new and what is old.\n";
}
