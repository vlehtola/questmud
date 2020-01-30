inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/dead_warrior");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/dead_ranger");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("south","/wizards/gynter/area2/city1/castleup0");
  /* setting desc */
  short_desc = "A small crypt";
  long_desc = "There are cascets lining the walls.\n"+
              "There are almost fifty cascets in this room and in the middle\n"+
              "of the room there are two large ones, open.\n";
}
