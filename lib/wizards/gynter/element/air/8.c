inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/la_a_guard");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("northeast","/wizards/gynter/element/air/5");
  add_exit("southwest","/wizards/gynter/element/air/11");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "Doorframes. Four doorframes and nothing more.\n"+
              "The floor is transparent, the roof is transparent and\n"+
              "the walls are transparent.\n";
  set_not_out(3);
  set_light(1);
}
