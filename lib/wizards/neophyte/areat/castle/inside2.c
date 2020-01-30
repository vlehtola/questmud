inherit "room/room";

reset(arg) {
        add_exit("south","inside1");
        add_exit("north","stairs");
short_desc = "Front of a huge tower";
long_desc = "A huge tower rises towards the sky just in front of you, reaching almost\n"+
            "the clouds, which are floating low. A steel stairs can be seen at north,\n"+
            "inside the tower. The tower is built of square stones, thick boards and\n"+
            "combined with clay.\n";
set_not_out(3);
}
