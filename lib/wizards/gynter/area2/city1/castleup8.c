inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castleup9.c");
  add_exit("west","/wizards/gynter/area2/city1/castleup7.c");
  /* setting desc */
  short_desc = "A narrow corridor";
  long_desc = "This is the smallest, dirtiest, most unused corridor you\n"+
              "have ever seen. The spiderwebs are two centimeters thick.\n";
}
