inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/temple0");
  add_exit("west","/wizards/gynter/area2/city2/temple8");
  /* setting desc */
  short_desc = "3:rd circle walk";
  long_desc = "Now the walls are showing the thought of long since gone warriors\n"+
              "and archmage's. And strangely one of the things repeating itself in\n"+
              "the images area the words: HAIL KAOS!!<tm>\n";
}
