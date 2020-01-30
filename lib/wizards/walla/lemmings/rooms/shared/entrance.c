inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("north", "/wizards/walla/lemmings/rooms/shared/awaypath1");
  add_exit("south", "/wizards/walla/lemmings/rooms/lvl3/virtual_map: 29 5");
  add_exit("east", "/wizards/walla/lemmings/rooms/lvl3/virtual_map: 29 5");
  add_exit("west", "/wizards/walla/lemmings/rooms/lvl3/virtual_map: 29 5");
  add_exit("southwest", "/wizards/walla/lemmings/lvl3/virtual_map: 29 5");
  add_exit("southeast", "/wizards/walla/lemmings/rooms/lvl3/virtual_map: 29 5");
  short_desc = "In a huge cavern deep underground";
  long_desc = "      ^^^      You are walking through a huge cavern, that has virtually\n"+
         "     ^^^^^     no roof. The ground is made of rock, that has been polished\n"+
              "    ^^^^^^^    with some sort of stones, and it's perfectly smooth.\n"+
              "   ccccc*ccc   The cave seems to have no end to it, and you really are\n"+
              "    cXccccX    amazed at the craftsmanship of the place\n"+
              "     cccXc \n"+
              "      ccc \n";


    call_other("wizards/walla/lemmings/rooms/lvl3/virtual_map.c", "start_map");
}
