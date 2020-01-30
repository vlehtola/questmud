inherit "room/room";

reset(arg) {
call_other("/wizards/kaappi/drow/vmap/virtual_map", "XX", 0);

  add_exit("north", "/wizards/kaappi/drow/vmap/virtual_map: 45 24");
  add_exit("enter", "/wizards/kaappi/drow/rooms/castle2/castle2_1.c");

  short_desc = "The castle of Maezynge";
  long_desc = "You are standing in front of the big castle.\n"+
              "There is a gorgoues looking archway leading\n"+
              "inside of it. A beatufil symbol is graved on the wall\n"+
              "and the text, Maezynge, is written below it.\n";
}
