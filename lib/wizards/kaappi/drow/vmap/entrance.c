inherit "room/room";

reset(arg) {
call_other("/wizards/kaappi/drow/vmap/virtual_map", "XX", 0);

  add_exit("west", "/wizards/kaappi/drow/vmap/virtual_map: 60 15");
  add_exit("out", "/wizards/kaappi/workroom.c");

  short_desc = "The caves of Elisrret";
  long_desc = "You have arrived to the narrow tunnel which is\n"+
              "leading to the west. The tunnel is very dark, only\n"+
              "some strange glowing mushrooms are giving light here.\n"+
              "Nearly complete silence and the darkness makes\n"+
              "you shiver in fear. Your senses are telling you to \n"+
              "turn around and leave this place alone.\n";
}
