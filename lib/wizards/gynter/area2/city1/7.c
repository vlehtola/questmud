inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon  && random(3)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/rat");
    move_object(demon, this_object());
  }
  if (!demon1 && random(3)) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/rat");
    move_object(demon1, this_object());
  }
  if (!demon2 && random(3)) {
    demon2 = clone_object("/wizards/gynter/area2/city1/mobs/rat");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/8");
  add_exit("west","/wizards/gynter/area2/city1/6");
  /* setting desc */
  short_desc = "Rat Alley";
  long_desc = "This is the real ghetto in Strekhard. The garbage\n"+
              "seems to get even denser in the middle of the street.\n"+
              "The rats forage through the garbage at every turn.\n";
}
