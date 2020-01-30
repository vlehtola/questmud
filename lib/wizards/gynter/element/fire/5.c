inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/f_cat");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/f_cat");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/f_cat1");
    move_object(demon2, this_object());
  }
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/fire/4");
  /* setting desc */
  short_desc = "A stop in the hallway";
  long_desc = "You come to a stop in the hallway.\n"+
              "The flames are everywhere except the way you came.\n";
}
