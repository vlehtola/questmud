inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("down", "/wizards/walla/lemmings/rooms/shared/2stairs");
  add_exit("east", "/wizards/walla/lemmings/rooms/lvl3/virtual_map: 16 19");
  short_desc = "whee, portaat";
  long_desc = "A long, wooden pier welcomes the sailors and adventurers to the island. It's\n"+
              "the view to the sea.\n";

      call_other("wizards/walla/lemmings/rooms/lvl3/virtual_map.c", "start_map");

}
