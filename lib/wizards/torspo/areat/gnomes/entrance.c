inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("north", "/wizards/torspo/areat/gnomes/hills02.c");
  add_exit("southwest", "out: 105 120");
  short_desc = "Grassy hills";
  long_desc = "A little path goes through the high hills all around you.\n"+
              "Only some low grass grows here, the ground is too barren and arid.\n"+
              "Small rocks are lying everywhere and it makes the walking hard.\n";
}
