inherit "room/room";
object monster;
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/gynter/area2/city1/mobs/ranger1");
    move_object(monster, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/3");
  add_exit("west","/wizards/gynter/area2/city1/1");
  /* setting desc */
  short_desc = "Courtyard";
  long_desc = "This is the courtyard outside the King's castle.\n"+
              "The ground is shimmering from the excellent care\n"+
              "that the rangers give it.\n";
}
