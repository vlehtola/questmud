inherit "room/room";
object demon, demon1, demon2, demon3;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/stone_giant");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/stone_giant");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/stone_giant");
    move_object(demon2, this_object());
  }
  if (!demon3) {
    demon3 = clone_object("/wizards/gynter/element/mobs/stone_giant");
    move_object(demon3, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/14");
  add_exit("north","/wizards/gynter/element/earth/10");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. And the most remarkable thing is\n"+
              "that there are tunnels leading in every direction out of here,\n"+
              "and there is no way anything could fit through that!\n";
  /* setting features */
  set_light(1);
}
