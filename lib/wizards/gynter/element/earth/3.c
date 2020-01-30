inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/4");
  add_exit("south","/wizards/gynter/element/earth/7");
  add_exit("west","/wizards/gynter/element/earth/2");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. And the most remarkable thing is\n"+
              "that there are small tunnels leading in every direction out of here.\n";
  /* setting features */
  set_light(1);
}
