inherit "room/room";
object demon, demon1, demon2;

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
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/granit_giant1");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/earth/15");
  add_exit("north","/wizards/gynter/element/earth/12");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything here is made\n"+
              "out of some kind of stone. It must be impossible to live in\n"+
              "in this harsh environment.\n";
  /* setting features */
  set_light(1);
}
