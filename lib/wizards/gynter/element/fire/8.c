inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/la_fire");
    move_object(demon, this_object());
  }
  /* Assigning exits */
  add_exit("north","/wizards/gynter/element/fire/7");
  add_exit("east","/wizards/gynter/element/fire/9");
  add_exit("south","/wizards/gynter/element/fire/11");
  /* setting desc */
  short_desc = "A crossway";
  long_desc = "You are standing in a crossway.\n"+
              "To the east there is a tiny hallway vanishing, and to the south\n"+
              "and north there are large hallways. The room burns with a white\n"+
              "light close to the east.\n";
}
