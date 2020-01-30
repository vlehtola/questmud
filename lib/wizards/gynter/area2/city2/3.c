inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(3)) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/citizen");
    move_object(demon, this_object());
  }
  if(!demon1 && random(3)) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/citizen");
    move_object(demon1, this_object());
  }
  if(!demon2 && random(3)) {
    demon2 = clone_object("/wizards/gynter/area2/city2/mobs/citizen");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/4");
  add_exit("south","/wizards/gynter/area2/city2/f");
  /* setting desc */
  short_desc = "A main road";
  long_desc = "This is the main road of the village.\n"+
              "It is used by several people and is quite crowded by day.\n"+
              "But strangely there aren't so much as a scratch on the road.\n";
}
