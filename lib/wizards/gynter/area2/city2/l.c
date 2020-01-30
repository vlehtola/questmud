inherit "room/room";
object demon, demon1, demon2, demon3;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(4)) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon, this_object());
  }
  if(!demon1 && random(3)) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon1, this_object());
  }
  if(!demon2 && random(4)) {
    demon2 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon2, this_object());
  }
  if(!demon3 && random(3)) {
    demon3 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("south","/wizards/gynter/area2/city2/p");
  /* setting desc */
  short_desc = "Approach to the holy center";
  long_desc = "The road continues closer to the Control Tower.\n"+
              "In the far a dark room can be seen but it is still far away.\n";
}
