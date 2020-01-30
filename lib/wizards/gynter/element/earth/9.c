inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("south","/wizards/gynter/element/earth/12");
  add_exit("west","/wizards/gynter/element/earth/8");
  add_exit("north","/wizards/gynter/element/earth/5");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. And the most remarkable thing is\n"+
              "that there are tunnels leading in every direction out of here,\n"+
              "and some are so small only a baby would fit through them.\n";
  /* setting features */
  set_light(1);
}
