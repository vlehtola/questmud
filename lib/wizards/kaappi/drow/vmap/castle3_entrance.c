inherit "room/room";

reset(arg) {
call_other("/wizards/kaappi/drow/vmap/virtual_map", "XX", 0);

  add_exit("northwest", "/wizards/kaappi/drow/vmap/virtual_map: 39 22");
  add_exit("enter", "/wizards/kaappi/drow/rooms/castle3/castle3_1.c");

  short_desc = "The castle of Hun'duis";
  long_desc = "In front of you there is a gorgeous looking\n"+
              "castle rising towards the ceiling of the tunnel.\n"+
              "A beautiful symbol of this family is graved on the\n"+
              "huge boulder which is leaning agains the wall.\n"+
              "Around the symbol there is a text which says,\n"+
              "The castle of Hun'duis.\n";
}
