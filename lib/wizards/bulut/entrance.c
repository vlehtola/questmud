inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("north", "/wizards/duncan/island/virtual_map: 27 26");
  add_exit("out", "/wizards/duncan/workroom.c");

  short_desc = "On a long, wooden pier";
  long_desc = "A long, wooden pier welcomes the sailors and adventurers to the island. The\n"+
              "pier looks strong, even the strong wind which blows, doesn't sway the pier.\n"+
              "The waves are hitting to the pier, splashing salty sea water over the pier.\n"+
              "The pier is big enough for five, big ships to dock at the same time. There\n"+
              "are ropes and fastening hooks all around the pier, waiting to the docking\n"+
              "ships. The boards in the pier are, either damaged or broken, and slippery\n"+
              "because of the salty sea water. A thick and wet mist is floating over the\n"+
              "whole island, blanketing the view to the sea.\n";

    items = allocate(6);
    items[0] = "ropes";
    items[1] = "The ropes are old, but strong, fastened to the fastening hooks";
    items[2] = "boards";
    items[3] = "The boards are either damaged or broken. They are slippery, because of the salty sea water";
    items[4] = "fastening hooks";
    items[5] = "The fastening hooks are rusty and there are ropes fastened to the hooks";

    call_other("wizards/duncan/island/virtual_map.c", "start_map");
}

