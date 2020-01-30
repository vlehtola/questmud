inherit "room/room";
 
reset(arg) {
        if(arg) return;
        add_exit("south","room8");
        add_exit("north","room7");
        short_desc = "Inside the cathedral";
        long_desc = "A great power can all but be tasted in the air, hanging like an oily film over the ground.\n" +
                    "Webs hang like tattered shrouds from every corner, and a dessicated body of a rat hangs\n" +
                    "wrapped in spider silk from the roof. On one of the corpse-gray walls, is a cabinet, six feet\n" +
                    "high by three feet wide by two feet deep, which holds a multitude of tiny drawers, each meticulously\n" +
		    "labeled in a language that you cannot comprehend. A horsehide chair sits in one dimly lit corner.\n";
        items = allocate(2);
        items[0] = "cabinet";
        items[1] = "A large cabinet with labeled drawers";
        property = allocate(1);
        property[0] = "no_summon";
}

