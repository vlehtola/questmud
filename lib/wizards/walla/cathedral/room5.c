inherit "room/room";
 
reset(arg) {
        if(arg) return;
        add_exit("south","/guilds/warlock/warlock");
        add_exit("north","room1");
        short_desc = "A large hall";
        long_desc = "A great power can all but be tasted in the air, hanging like an oily film over the ground.\n" +
                    "Webs hang like tattered shrouds from every corner, and a dessicated body of a rat hangs\n" +
                    "wrapped in spider silk from the roof. There are some markings on the cold stone floor, that indicate\n" +
                    "some sort of rituals. The corpse-gray walls are covered with hundreds of feet of copper wiring, being\n" +
		    "able to channel the enormous powers which are used in this room. There is no roof in this room, and the\n" +
                    "foul weather is kept away by a magic spell. The stones in the wall have been exactly placed, in order to\n" +
                    "preserve the integrity of the walls.\n";
        items = allocate(2);
        items[0] = "cabinet";
        items[1] = "A large cabinet with labeled drawers";
        property = allocate(1);
        property[0] = "no_summon";
}
