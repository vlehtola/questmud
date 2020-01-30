inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/earth/16");
  add_exit("west","/wizards/gynter/element/earth/14");
  add_exit("north","/wizards/gynter/element/earth/1");
  /* setting desc */
  short_desc = "The land of stone";
  long_desc = "This is the vast land of stone. Everything inhere is made\n"+
              "out of some kind of stone. And the most remarkable thing is\n"+
              "that there are tunnels leading in every direction out of here.\n"+
              "Although some are smaller than a four yearold child.\n";
  /* setting features */
  set_light(1);
}
