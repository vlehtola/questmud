inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/castleup4.c");
  add_exit("south","/wizards/gynter/area2/city1/castleup9.c");
  /* setting desc */
  short_desc = "A narrow corridor";
  long_desc = "This is the smallest, dirtiest, most unused corridor you\n"+
              "have ever seen. There is five centimeters of dust on the\n"+
              "floor and the spiderwebs are two centimeters thick.\n";
}
