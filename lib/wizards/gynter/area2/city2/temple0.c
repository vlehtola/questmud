inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/templea");
  add_exit("west","/wizards/gynter/area2/city2/temple9");
  add_exit("north","/wizards/gynter/area2/city2/temple6");
  /* setting desc */
  short_desc = "2:nd circle walk";
  long_desc = "Now the corridor is getting finer with each step. Before there\n"+
              "was nothing but naked walls but now the walls are magically decorated\n"+
              "with the thought's of the bypasser.\n";
}
