inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("south","room3");
        add_exit("east","room1");
        short_desc = "inside the cathedral";
        long_desc = "A great power can all but be tasted in the air, hanging like an oily film over the ground. " +
                    "Webs hang like tattered shrouds from every corner, and a dessicated body of a rat hangs " +
                    "wrapped in spider silk from the roof. On one of the corpse-gray walls, is a cabinet, six feet " +
                    "high by three feet wide by two feet deep, which holds a multitude of tiny drawers, each meticulously " +
		    "labeled in a language that you cannot comprehend. A horsehide chair sits in one dimly lit corner.\n";
        items = allocate(4);
        items[0] = "cabinet";
        items[1] = "A large cabinet made from black wood with labeled drawers is placed standing next to the wall";
        items[2] = "chair";
        items[3] = "A wooden chair is next to cabinet and the chair is covered with dust that has come from the many years";
        property = allocate(1);
        property[0] = "no_summon";
        set_not_out(1);
        set_light(0);
}
query_startroom() { return 1; }