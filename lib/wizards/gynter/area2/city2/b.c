inherit "room/room";
object demon, demon1;
reset(arg) {
  /* Applying mobs */
  if(!demon && random(4)) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/citizen");
    move_object(demon, this_object());
  }
  if(!demon1 && random(4)) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/citizen");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/c");
  add_exit("west","/wizards/gynter/area2/city2/a");
  /* setting desc */
  short_desc = "A main road";
  long_desc = "This is the main road of the village.\n"+
              "It is used by several people and is quite crowded by day.\n"+
              "But strangely there aren't so much as a scratch on the road.\n";
}
