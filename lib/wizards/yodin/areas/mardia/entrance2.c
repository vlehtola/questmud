inherit "room/room";

reset(arg) {
call_other("/wizards/yodin/areas/mardia/virtual_map", "XX", 0);




 add_exit("out", "/wizards/yodin/areas/mardia/virtual_map: 11 2");
add_exit("south", "?");

  short_desc = "cave";
  long_desc =   "e.\n";

}
