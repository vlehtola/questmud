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
  add_exit("east","/wizards/gynter/element/air/2");
  add_exit("southwest","/wizards/gynter/element/air/3");
  add_exit("out","/wizards/gynter/element/gateway");
  /* setting desc */
  short_desc = "The Entrance to the plane of air";
  long_desc = "There is nothing around you except darkness.\n"+
              "There is no floor, ceiling or walls. Just a vast\n"+
              "emptyness. Infact the only thing you can see that signals\n"+
              "that this is a room is the doorframes that you see.\n";
  set_not_out(3);
  set_light(1);
}
