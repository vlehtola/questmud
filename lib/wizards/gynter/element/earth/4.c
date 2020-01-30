inherit "room/room";
object demon, demon1;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/granit_giant");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/granit_giant");
    move_object(demon1, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/5");
  add_exit("south","/wizards/gynter/element/earth/8");
  add_exit("west","/wizards/gynter/element/earth/3");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. Looks like marble.\n";
  /* setting features */
  set_light(1);
}
