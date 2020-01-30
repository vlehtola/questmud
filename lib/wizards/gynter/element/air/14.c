inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/hu_a_guard1");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("northwest","/wizards/gynter/element/air/10");
  add_exit("west","/wizards/gynter/element/air/13");
  add_exit("southwest","/wizards/gynter/element/air/15");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "The walls, floor and ceiling seems to be made by\n"+
              "smoke trapped in something. It looks like air gone hard.\n";
  set_not_out(3);
  set_light(1);
}
