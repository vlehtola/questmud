inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("north", "/wizards/duncan/island/virtual_map: 27 26");
 
  short_desc = "On a long, wooden pier";
  long_desc = "A long, wooden pier welcomes the sailors and adventurers to the island. It's\n"+
              "looking strong, even the strong wind which blows, doesn't sway it. The waves\n"+
              "are hitting to the pier, splashing salty sea water over it. It's big enough\n"+
              "for five, big ships to dock at the same time. There are ropes and fastening\n"+
              "hooks all around the pier, waiting to the docking ships. The boards in the\n"+
              "pier are either damaged or broken, and slippery because of the salty sea\n"+
              "water. A thick and wet mist is floating over the whole island, blanketing\n"+
              "the view to the sea.\n";

    items = allocate(6);
    items[0] = "ropes";
    items[1] = "The ropes are old, but strong, fastened to the fastening hooks";
    items[2] = "boards";
    items[3] = "The boards are either damaged or broken. They are slippery, because of the salty sea water";
    items[4] = "fastening hooks";
    items[5] = "The fastening hooks are rusty and there are ropes fastened to the hooks";

    call_other("wizards/duncan/island/virtual_map.c", "start_map");
}

