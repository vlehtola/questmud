inherit "room/room";
object demon;
reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/citizen");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/d");
  add_exit("west","/wizards/gynter/area2/city2/b");
  /* setting desc */
  short_desc = "A main road";
  long_desc = "This is the main road of the village.\n"+
              "It is used by several people and is quite crowded by day.\n"+
              "But strangely there aren't so much as a scratch on the road.\n"+
              "The road is so intact and unscathed that it looks like the surface\n"+
              "of a lake on a clear windless day.\n";
}