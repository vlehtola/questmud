inherit "room/room";
object demon, demon1;

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
  /* Assigning exits */
  add_exit("north","/wizards/gynter/element/fire/6");
  add_exit("south","/wizards/gynter/element/fire/8");
  /* setting desc */
  short_desc = "A large hallway";
  long_desc = "You are standing in a large hallway.\n"+
              "The walls are made out of burning fires, and in the fires\n"+
              "there are scenes from battles fought ages ago between\n"+
              "the various lords of this realm.\n";
}
