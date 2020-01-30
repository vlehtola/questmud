inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/med_a_guard");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/air/5");
  add_exit("east","/wizards/gynter/element/air/7");
  add_exit("south","/wizards/gynter/element/air/9");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "A room with no walls. The floor is barely visible but\n"+
              "only because there seems to be some kind of smoke trapped in it.\n";
  set_not_out(3);
  set_light(1);
}
