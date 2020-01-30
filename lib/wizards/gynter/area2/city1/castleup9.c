inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("west","/wizards/gynter/area2/city1/castleup8.c");
  add_exit("north","/wizards/gynter/area2/city1/castleup5.c");
  /* setting desc */
  short_desc = "A narrow corridor";
  long_desc = "This is the smallest, dirtiest, most unused corridor you\n"+
              "have ever seen. There is five centimeters of dust on the floor and\n"+
              "the spiderwebs are two centimeters thick. You just hope that you\n"+
              "won't encounter the spiders that did those webs.\n";
}
