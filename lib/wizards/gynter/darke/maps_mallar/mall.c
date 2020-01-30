inherit "room/room";
object mob, mob1, mob2, mob3;

reset(arg) {
  /* Applying mobs */
  if(!mob) {
    mob = clone_object("/wizards/gynter/darke/mobs/");
    move_object(mob, this_object());
  }
  if (!mob1) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/");
    move_object(mob1, this_object());
  }
  if(!mob2) {
    mob2 = clone_object("/wizards/gynter/darke/mobs/");
    move_object(mob2, this_object());
  }
  if (!mob3) {
    mob3 = clone_object("/wizards/gynter/darke/mobs/");
    move_object(mob3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("","/wizards/gynter/darke/city/");
  add_exit("","/wizards/gynter/darke/city/");
  add_exit("","/wizards/gynter/darke/city/");
  add_exit("","/wizards/gynter/darke/city/");
  /* setting desc */
  short_desc = "";
  long_desc = "\n"+
              "\n"+
              "\n"+
              "\n";
}
