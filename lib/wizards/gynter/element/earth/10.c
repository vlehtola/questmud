inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/11");
  add_exit("south","/wizards/gynter/element/earth/13");
  add_exit("north","/wizards/gynter/element/earth/6");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. It must be impossible to live in\n"+
              "in this harsh environment.\n";
  /* setting features */
  set_light(1);
}
