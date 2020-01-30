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
  add_exit("west","/wizards/gynter/element/air/6");
  add_exit("southeast","/wizards/gynter/element/air/10");
  add_exit("northwest","/wizards/gynter/element/air/4");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "There is nothing around you at all. Just a vast emptyness.\n"+
              "Infact the only thing you can see that signals that this is\n"+
              "a room is the doorframes of the doors that lead out of here.\n";
  set_not_out(3);
  set_light(1);
}
