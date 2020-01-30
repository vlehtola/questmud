inherit "room/room";
object demon, demon1, demon2, demon3;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/med_fire");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/med_fire");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/med_fire");
    move_object(demon2, this_object());
  }
  if(!demon3) {
    demon3 = clone_object("/wizards/gynter/element/mobs/med_fire");
    move_object(demon3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/fire/9");
  /* setting desc */
  short_desc = "The room of eternal fire";
  long_desc = "The minute you step into the room you have to put your\n"+
              "hand before your eyes because the light from the fires burning\n"+
              "in here are so blinding. When your eyes have adapted to the bright\n"+
              "light you can barely make out parts of a word floating in the middle\n"+
              "of the room.    Tir... \n";
}
