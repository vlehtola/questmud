inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/f_guard");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/f_guard");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/f_guard");
    move_object(demon2, this_object());
  }
  /* Assigning exits */
  add_exit("north","/wizards/gynter/element/fire/13");
  add_exit("northwest","/wizards/gynter/element/fire/15");
  /* setting desc */
  short_desc = "A stop in the hallway";
  long_desc = "You come to a stop in the hallway.\n"+
              "There are fires everywhere except from where you came.\n";
}
