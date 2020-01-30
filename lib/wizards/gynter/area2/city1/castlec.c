inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/red_guard");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/red_guard");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/area2/city1/mobs/king");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/castle6");
  /* setting desc */
  short_desc = "The kings chambers";
  long_desc = "You have now reached the kings chambers.\n"+
              "This is the most inner sanctum, noone without the kings\n"+
              "blessings may step into this room and leave, alive.\n";
}
