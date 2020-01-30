inherit "room/room";
object demon,demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon, this_object());
  }
  if(!demon1 && random(5)) {
    demon1 = clone_object("/wizards/gynter/area2/city2/mobs/priest");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("out","/wizards/gynter/area2/city2/v");
  add_exit("south","/wizards/gynter/area2/city2/temple2");
  /* setting desc */
  short_desc = "1:st circle walk";
  long_desc = "This is the beginning of the first circle.\n"+
              "The walls are bare and no attempts have been\n"+
              "made to make this place more beutifull.\n";
}
