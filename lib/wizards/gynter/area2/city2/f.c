inherit "room/room";
object demon, demon1, demon2, demon3;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(2)) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon, this_object());
  }
  if(!demon1 && random(2)) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon1, this_object());
  }
  if(!demon2 && random(2)) {
    demon2 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon2, this_object());
  }
  if(!demon3 && random(2)) {
    demon3 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("south","/wizards/gynter/area2/city2/l");
  /* setting desc */
  short_desc = "Approach to the holy center";
  long_desc = "This is the road that connect to one of the control towers.\n"+
              "The road seems to be built out of diamonds! And strangely enough\n"+
              "it seems to be no way in walking north.\n";
}