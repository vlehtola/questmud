inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("down", "/wizards/walla/lemmings/rooms/shared/1stairs");
  add_exit("up", "wizards/walla/lemmings/rooms/shared/3stairs");
  add_exit("east", "/wizards/walla/lemmings/rooms/lvl2/virtual_map: 16 19");
  short_desc = "whee, portaat";
  long_desc = "A long, wooden pier welcomes the sailors and \n"+
              "turers to the island. It's the view to the sea.\n";

      call_other("wizards/walla/lemmings/rooms/lvl2/virtual_map.c", "start_map"
    );

}

