inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(4)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/citizen");
    move_object(demon, this_object());
  }
  if (!demon1 && random(4)) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/citizen");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/l");
  add_exit("south","/wizards/gynter/area2/city1/v");
  /* setting desc */
  short_desc = "The Golden Walk";
  long_desc = "Once this road was covered with gold, the houses covered with\n"+
              "gold. Everything was covered with gold, but now it is just mud.\n";
}
