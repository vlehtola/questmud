inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(2)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/knight");
    move_object(demon, this_object());
  }
  if (!demon1 && random(2)) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/knight");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castlem");
  add_exit("north","/wizards/gynter/area2/city1/castlee");
  /* setting desc */
  short_desc = "A crude stone corridor";
  long_desc = "The masonry in this corridor is about to become dust.\n"+
              "The corridor continues as far as you can see.\n";
}
