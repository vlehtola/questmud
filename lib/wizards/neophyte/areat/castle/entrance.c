inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Entrance to castle";
        long_desc = "You are standing in front of a small gate, which leads to the castle.\n"+
                    "On the ground is lots of tracks, different sized footprints, left by\n"+
                    "other travellers on their journeys. Lots of bushes and trees can be\n"+
                    "seen just near the gate.\n";
    items = allocate(4);
    items[0] = "trees";
    items[1] = "Lots of rotten trees are growing just near the gate";
    items[2] = "bushes";
    items[3] = "Bushes are growing just near the gate";
  /* exits renamed by Celtron */
    add_exit("gate","gateway");
    add_exit("out", "out: 185 68");
}
