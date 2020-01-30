inherit "room/room";

reset(arg) {
call_other("/wizards/kaappi/drow/vmap/virtual_map", "XX", 0);

  add_exit("southeast", "/wizards/kaappi/drow/vmap/virtual_map: 27 15");
  add_exit("southwest", "/wizards/kaappi/drow/vmap/virtual_map: 27 15");
  add_exit("enter", "/wizards/kaappi/drow/rooms/castle5/r1.c");

  short_desc = "The castle of Teken'afin";
  long_desc = "You are standing in front of the castle. This castle\n"+
              "is much bigger than others in this cave. There are three\n"+
              "gorgeous looking high towers rising up, almost reaching the\n"+
              "ceiling of the cave. There is a huge symbol graved on the wall\n"+
              "and below it there is a text, Teken'afin.\n";
}
