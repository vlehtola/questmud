inherit "room/room";

reset (arg) {

    add_exit("stairs","stairs2");
        short_desc = "Resting room of clerics";
        long_desc = "A private resting place of clerics. The room looks very\n"+
                    "simple maybe its because clerics are never resting. A couple\n"+
                    "of iron bedstead are placed near the north wall. A wooden table\n"+
                    "is center of the room. Small fireplace made from red bricks is\n"+
                    "giving warmth to this dark and cold room.\n";
        set_not_out(1);
        set_light(2);
}
