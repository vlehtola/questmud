inherit "room/room";
object demon;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/hu_a_guard");
    move_object(demon, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/element/air/9");
  add_exit("east","/wizards/gynter/element/air/13");
  add_exit("southeast","/wizards/gynter/element/air/15");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "There is nothing around you at all. There is no floor, ceiling,\n"+
              "or walls. Just a vast emptyness. Infact the only thing you can\n"+
              "see that signals that this is a room is the doorframes of the\n"+
              "doors that lead out of here.\n";
  set_not_out(3);
  set_light(1);
}
