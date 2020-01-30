inherit "room/room";
object demon, demon1, demon2, demon3;

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
    demon2 = clone_object("/wizards/gynter/element/mobs/f_dog");
    move_object(demon2, this_object());
  }
  if(!demon3) {
    demon3 = clone_object("/wizards/gynter/element/mobs/f_dog");
    move_object(demon3, this_object());
  }
  /* Assigning exits */
  add_exit("north","/wizards/gynter/element/fire/8");
  add_exit("south","/wizards/gynter/element/fire/12");
  /* setting desc */
  short_desc = "A large hallway";
  long_desc = "You are standing in a large hallway.\n"+
              "The walls are made out of burning fires, and if you look too\n"+
              "long into them you start to see scenes from battles fought\n"+
              "ages ago between the various lords of this realm.\n";
}
