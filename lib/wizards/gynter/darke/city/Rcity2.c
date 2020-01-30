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
  add_exit("north","/wizards/gynter/darke/city/guard/virtual_guard_map: 36 18");
  add_exit("east","/wizards/gynter/darke/city/Rcity3");
  add_exit("west","/wizards/gynter/darke/city/Rcity1");
  /* setting desc */
  short_desc = "The central city walk";
  long_desc = "This is the new road that divides the new and old\n"+
              "parts of the city. In some parts there can be seen\n"+
              "beauty. But only in a few places.\n";
}
