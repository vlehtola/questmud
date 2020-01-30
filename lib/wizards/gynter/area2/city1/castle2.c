inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/knight");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/knight");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castle3");
  add_exit("west","/wizards/gynter/area2/city1/castle1");
  /* setting desc */
  short_desc = "A crude stone corridor";
  long_desc = "You are standing in a crude stone corridor.\n"+
              "The masonry that keeps the stone in the wall and ceiling\n"+
              "is about to become dust. The corridor continues as far as\n"+
              "you can see.\n";
}
