inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/sm_fire");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/sm_fire");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/sm_fire");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/fire/2");
  add_exit("south","/wizards/gynter/element/fire/6");
  add_exit("out","/wizards/gynter/element/gateway");
  /* setting desc */
  short_desc = "Entrance to the plane of fire";
  long_desc = "This is a room born in fire. Every place of this room is burning\n"+
             "with these cursed flames. And the flames aren't even hot.\n";
}
