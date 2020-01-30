inherit "room/room";
object demon, demon1, demon2;

reset(arg) {
  /* Applying mobs */
  if(!demon) {
    demon = clone_object("/wizards/gynter/element/mobs/clay_giant");
    move_object(demon, this_object());
  }
  if (!demon1) {
    demon1 = clone_object("/wizards/gynter/element/mobs/clay_giant");
    move_object(demon1, this_object());
  }
  if (!demon2) {
    demon2 = clone_object("/wizards/gynter/element/mobs/clay_giant");
    move_object(demon2, this_object());
  }
  if(arg) return;
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/1");
  add_exit("south","/wizards/gynter/element/earth/14");
  add_exit("west","/wizards/gynter/element/earth/10");
  add_exit("north","/wizards/gynter/element/earth/7");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. This is truly the land of the stone giants.\n";
  /* setting features */
  set_light(1);
}
