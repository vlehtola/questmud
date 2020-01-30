inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/9");
  add_exit("enter","/wizards/gynter/area2/city2/temple1");
  /* setting desc */
  short_desc = "The holy center";
  long_desc = "This is the holy center of the village\n"+
              "This is the entrance to the grand temple. This is the only\n"+
              "way in, and the only way out of the temple.\n";
}
