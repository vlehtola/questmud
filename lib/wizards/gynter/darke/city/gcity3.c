inherit "room/room";
object mob, mob1, mob2, mob3;
reset(arg) {
  /* Applying mobs */
  if(!mob) {
    mob = clone_object("/wizards/gynter/darke/mobs/lazy_guards");
    move_object(mob, this_object());
  }
  if(!mob1 && !random(2)) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/lazy_guards");
    move_object(mob1, this_object());
  }
  if(!mob2 && !random(2)) {
    mob2 = clone_object("/wizards/gynter/darke/mobs/lazy_guards");
    move_object(mob2, this_object());
  }
  if(!mob3 && !random(2)) {
    mob3 = clone_object("/wizards/gynter/darke/mobs/lazy_guards");
    move_object(mob3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/darke/city/Wcity2");
  add_exit("west","/wizards/gynter/darke/city/guard/virtual_guard_map: 38 15");
  /* setting desc */
  short_desc = "Guard Room";
  long_desc = "This is where the guards wait when they\n"+
              "are on guardduty. This is because they need\n"+
              "to be able to respond in a hurry.\n";
}
