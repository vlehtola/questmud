inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("south","/wizards/gynter/area2/city2/o");
  /* setting desc */
  short_desc = "Approach to the holy center";
  long_desc = "This is the road that connect to one of the control towers.\n"+
              "The road seems to be built out of diamonds! And strangely enough\n"+
              "it seems to be no way in walking north.\n";
}
