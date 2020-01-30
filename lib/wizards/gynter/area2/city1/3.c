inherit "room/room";
object monster, monster1;

reset(arg) {
  /* Applying mobs */
  if(!monster && random(4)) {
    monster = clone_object("/wizards/gynter/area2/city1/mobs/ranger");
    move_object(monster, this_object());
  }
  if (!monster1 && random(4)) {
    monster1 = clone_object("/wizards/gynter/area2/city1/mobs/ranger");
    move_object(monster1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/4");
  add_exit("west","/wizards/gynter/area2/city1/2");
  /* setting desc */
  short_desc = "Courtyard";
  long_desc = "This is the courtyard outside the\n"+
              "King's castle. This is also the place\n"+
              "where the King's rangers train and live.\n";
}
