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
  add_exit("north","/wizards/gynter/area2/city1/castle7");
  add_exit("south","/wizards/gynter/area2/city1/castlek");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "This is the kings walk, it is rumored to be the only safe\n"+
              "haven left for the king. But now noone can be sure of anything.\n"+
              "Now the corridor is in such a depraved state that you can't seem\n"+
              "to figure out how the king can live in this castle.\n";
}
