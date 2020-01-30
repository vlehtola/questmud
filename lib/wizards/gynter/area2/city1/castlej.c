inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/white_paladin");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/white_paladin");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castlek");
  add_exit("west","/wizards/gynter/area2/city1/castlei");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "The corridor is in such a depraved state that you can't seem\n"+
              "to figure out how the king can live in this castle.\n"+
              "The walls are crumbling, the roof looks like it's about\n"+
              "to fall down and in some places it has.\n";
}
