inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/5");
  /* setting desc */
  short_desc = "Main road leaving the control towers";
  long_desc = "This is the main road that leads away from the towers.\n"+
              "Strangely it seems impossible to walk south.\n"+
              "The walls are closing in on themself behind you.\n";
}
