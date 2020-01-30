inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/med_air");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/med_air");
    move_object(demon1, this_object());
  }
  if(!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/med_air");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/air/1");
  add_exit("southeast","/wizards/gynter/element/air/4");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "There is nothing around you at all. There is no floor, ceiling,\n"+
              "or walls. Just a vast emptyness. Infact the only thing you can\n"+
              "see that signals that this is a room is the doorframes\n"+
              "that lead out of here. Doorframes are made out of solid air.\n";
  set_not_out(3);
  set_light(1);
}
