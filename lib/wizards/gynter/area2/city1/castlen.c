inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(5)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/knight");
    move_object(demon, this_object());
  }
  if (!demon1 && random(5)) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/knight");
    move_object(demon1, this_object());
  }
  if (!demon2 && random(5)) {
    demon2 = clone_object("/wizards/gynter/area2/city1/mobs/knight");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castleo");
  add_exit("west","/wizards/gynter/area2/city1/castlem");
  /* setting desc */
  short_desc = "A crude stone corridor";
  long_desc = "You are standing in a crude stone corridor.\n"+
              "The masonry in the walls are crumbling.\n"+
              "The corridor continues as far as you can see.\n";
}
