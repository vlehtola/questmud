inherit "room/room";
object mob, mob1, mob2, mob3;
reset(arg) {
  /* Applying mobs */
  if(!mob) {
    mob = clone_object("/wizards/gynter/darke/mobs/rat");
    move_object(mob, this_object());
  }
  if (!mob1) {
    mob1 = clone_object("/wizards/gynter/darke/mobs/rat");
    move_object(mob1, this_object());
  }
  if(!mob2 && !random(5)) {
    mob2 = clone_object("/wizards/gynter/darke/mobs/rat");
    move_object(mob2, this_object());
  }
  if (!mob3 && !random(5)) {
    mob3 = clone_object("/wizards/gynter/darke/mobs/rat");
    move_object(mob3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Orcity3");
  add_exit("south","/wizards/gynter/darke/city/Scity3");
  add_exit("southeast","/wizards/gynter/darke/city/Scity4");
  add_exit("southwest","/wizards/gynter/darke/city/Scity2");
  /* setting desc */
  short_desc = "The Slum";
  long_desc = "The slum is exactly what it is. A slum.\n"+
              "Huge rats are running everywhere and foraging this sewage.\n";
}
