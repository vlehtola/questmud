inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/castleup2.c");
  add_exit("down","/wizards/gynter/area2/city1/castlec.c");
  /* setting desc */
  short_desc = "A narrow corridor";
  long_desc = "This is the smallest, dirtiest, most unused corridor you\n"+
              "have ever seen. There is two inches of dust on the floor and\n"+
              "the spiderwebs are one inch thick. You just hope that you\n"+
              "won't encounter the spiders that did those webs.\n";
}
