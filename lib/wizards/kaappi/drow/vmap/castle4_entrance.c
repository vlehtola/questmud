inherit "room/room";

reset(arg) {
call_other("/wizards/kaappi/drow/vmap/virtual_map", "XX", 0);

  add_exit("east", "/wizards/kaappi/drow/vmap/virtual_map: 33 12");
  add_exit("enter", "/wizards/kaappi/drow/rooms/castle4/castle4_1.c");

  short_desc = "The castle of Baenafin";
  long_desc = "A huge and gorgeous looking castle raises\n"+
              "in front of you. Some strange animals can be\n"+
              "seen climbing on the walls of the castle. A huge\n"+
              "symbol is engraved on the wall and the text, Baenafin,\n"+
              "is written below it.\n";
}
