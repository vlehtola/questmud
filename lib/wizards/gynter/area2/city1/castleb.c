inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon && random(4)) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/white_paladin");
    move_object(demon, this_object());
  }
  if (!demon1 && random(4)) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/white_paladin");
    move_object(demon1, this_object());
  }
  if (!demon2 && random(4)) {
    demon2 = clone_object("/wizards/gynter/area2/city1/mobs/white_paladin");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/castle5");
  add_exit("west","/wizards/gynter/area2/city1/castlea");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "This is the kings walk, it is rumored to be the only safe\n"+
              "haven left for the king. But now noone can be sure of anything.\n"+
              "Now the corridor is in such a depraved state that you can't seem\n"+
              "to figure out how the king can live in this castle.\n";
}
