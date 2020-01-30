inherit "room/room";

reset(arg) {

  if(arg) return;

  add_exit("out", "/wizards/duncan/island/mainentrance.c");

  short_desc = "A small wooden pier has been built on the beach";
  long_desc = "A wooden pier has been built on the beach. There is only one docking\n"+
              "place for one small boat at the time. This is perfect place to dock\n"+
              "shelter from the storm. The pier is directed towards a huge island,\n"+
              "which is towards south couple miles from the mainland. The wooden pier\n"+
              "is in very bad condition, probably because of heavy traffic between\n"+
              "the mainland and the island. A thick mist is floating over the island,\n"+
              "blanketing the view to the island. The ropes and fastening hooks on\n"+
              "the pier are waiting for the boats to dock.\n";

    items = allocate(6);
    items[0] = "pier";
    items[1] = "The wooden pier is in very bad condition, because of the heavy traffic between the mainland and the island";
    items[2] = "ropes";
    items[3] = "The ropes are waiting for the boats to dock";
    items[2] = "fastening hooks";
    items[3] = "The fastening hooks are waiting for the boats to dock";

}
