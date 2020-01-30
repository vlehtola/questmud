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
  add_exit("north","/wizards/gynter/darke/city/guard/virtual_guard_map: 35 18");
  add_exit("south","/wizards/gynter/darke/city/Fcity1");
  add_exit("east","/wizards/gynter/darke/city/Rcity2");
  /* setting desc */
  short_desc = "The central city walk";
  long_desc = "This is the end of the Central city walk.\n"+
              "To the west the only thing to be seen is a solid\n"+
              "stonewall.\n";
}
