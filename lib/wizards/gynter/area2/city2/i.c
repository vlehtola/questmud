inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/0");
  /* setting desc */
  short_desc = "The baker";
  long_desc = "This is a tiny bakers shop. This is probably the only shop\n"+
              "in this city that is still opened. But it won't be for long,\n"+
              "because they don't have any bread anymore. Nor any of the\n"+
              "ingredients that they need to bake more bread.\n";
}
