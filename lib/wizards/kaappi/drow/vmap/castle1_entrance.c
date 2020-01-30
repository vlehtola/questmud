inherit "room/room";

reset(arg) {
call_other("/wizards/kaappi/drow/vmap/virtual_map", "XX", 0);

  add_exit("south", "/wizards/kaappi/drow/vmap/virtual_map: 46 12");
  add_exit("southeast", "/wizards/kaappi/drow/vmap/virtual_map: 46 12");
  add_exit("enter", "/wizards/kaappi/drow/rooms/castle1/castle1_1.c");

  short_desc = "The castle of Desprahel";
  long_desc = "There is a gorgeous looking castle in front of you.\n"+
              "One huge tower is rising in the middle of the castle.\n"+
              "A symbol is painted on the wall and below it there is\n"+
              "a text which says, Desprahel.\n";
}
