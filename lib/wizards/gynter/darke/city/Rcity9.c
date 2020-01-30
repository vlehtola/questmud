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
  add_exit("north","/wizards/gynter/darke/city/hall/virtual_hall_map: 30 24");
  add_exit("west","/wizards/gynter/darke/city/Rcity8");
  /* setting desc */
  short_desc = "The central city walk";
  long_desc = "This is the end of the Central city walk.\n"+
              "To the east the only thing to be seen is a solid\n"+
              "stonewall.\n";
}
