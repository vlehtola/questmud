inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/f_dog");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/f_dog");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/fire/3");
  add_exit("east","/wizards/gynter/element/fire/5");
  /* setting desc */
  short_desc = "A wide corridor";
  long_desc = "You are standing in a wide corridor.\n"+
              "Suddenly the corridor widens and it is now enormous.\n";
}
