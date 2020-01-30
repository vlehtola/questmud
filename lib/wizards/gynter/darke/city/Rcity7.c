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
  add_exit("north","/wizards/gynter/darke/city/hall/virtual_hall_map: 28 24");
  add_exit("east","/wizards/gynter/darke/city/Rcity8");
  add_exit("west","/wizards/gynter/darke/city/Rcity6");
  /* setting desc */
  short_desc = "The central city walk";
  long_desc = "This is not a beutiful street. Everywhere you can see trash,\n"+
              "below windows, besides doors and in the middle of the street.\n"+
              "The darkelfs cannot be much for cleaning.\n";
}
