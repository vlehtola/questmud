inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/la_air");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/la_air");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("northeast","/wizards/gynter/element/air/8");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "There is nothing around you at all. There is no floor, ceiling,\n"+
              "or walls. Just a vast emptyness. Infact the only thing you can\n"+
              "see that signals that this is a room is the doorframes of the\n"+
              "doors that lead out of here. And some kind of writing hovering\n"+
              "in the middle of the room. It says: .irp..\n";
  set_not_out(3);
  set_light(1);
}
