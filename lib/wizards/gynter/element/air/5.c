inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/la_a_guard");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/la_a_guard");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/air/6");
  add_exit("northeast","/wizards/gynter/element/air/3");
  add_exit("southwest","/wizards/gynter/element/air/8");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "There is nothing around you at all. There is no floor, ceiling,\n"+
              "or walls. Just a vast emptyness. There is only doorframes that\n"+
              "exist in here.\n";
  set_not_out(3);
  set_light(1);
}
