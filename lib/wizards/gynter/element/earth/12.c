inherit "room/room";
object demon, demon1;

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
  if(arg) return;
  /* Assigning exits */
  add_exit("south","/wizards/gynter/element/earth/16");
  add_exit("west","/wizards/gynter/element/earth/1");
  add_exit("north","/wizards/gynter/element/earth/9");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. And the most remarkable thing is\n"+
              "that there are tunnels leading in every direction out of here,\n"+
              "and some are so small only a baby would fit through them.\n";
  /* setting features */
  set_light(1);
}
