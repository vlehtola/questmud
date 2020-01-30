inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/7");
  add_exit("south","/wizards/gynter/element/earth/10");
  add_exit("north","/wizards/gynter/element/earth/2");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. The most remarkable thing is\n"+
              "that there are tunnels leading in some directions out of here,\n"+
              "and some are so small only a baby would fit through them.\n";
  /* setting features */
  set_light(1);
}
