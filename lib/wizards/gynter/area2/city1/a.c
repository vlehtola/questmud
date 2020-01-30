inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/area2/city1/mobs/rat");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/area2/city1/mobs/rat");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/b");
  add_exit("west","/wizards/gynter/area2/city1/9");
  /* setting desc */
  short_desc = "Rat Alley";
  long_desc = "This is the real ghetto in Strekhard.\n"+
              "There lies garbage in the corners of the walls and houses.\n"+
              "There doesn't seem to be a bit of clean space anywhere!\n";
}
