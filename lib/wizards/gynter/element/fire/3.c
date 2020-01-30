inherit "room/room";
object demon, demon1, demon2;

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
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/fire/2");
  add_exit("east","/wizards/gynter/element/fire/4");
  /* setting desc */
  short_desc = "A small corridor";
  long_desc = "You are standing in a small corridor.\n"+
              "There is almost no room to walk without touching\n"+
              "the flames in the walls. It is however impossible\n"+
               "to avoid stepping in the flames.\n";
}
