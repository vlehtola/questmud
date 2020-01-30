inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("south","/guilds/warlock/warlock");
        add_exit("north","room1");
        short_desc = "A large summoning chamber";
        long_desc = "A great power can all but be tasted in the air, hanging like an oily film over the ground. " +
                    "Webs hang like tattered shrouds from every corner, and a dessicated body of a rat hangs " +
                    "wrapped in spider silk from the roof. There are some markings on the cold stone floor, that indicate " +
                    "some sort of rituals. The corpse-gray walls are covered with hundreds of feet of copper wiring, being " +
		            "able to channel the enormous powers which are used in this room. There is no roof in this room, and the " +
                    "foul weather is kept away by a magic spell. The stones in the wall have been exactly placed, in order to " +
                    "preserve the integrity of the walls.\n";
        items = allocate(8);
        items[0] = "webs";
        items[1] = "The walls and ceiling are full of the webs what are hanging like a tattered shrouds. A dead body of rat is inside of somekind of wrapped silk";
        items[2] = "markings";
        items[3] = "The markins are showing somekind of summoning ritual that the warlocks are trying to archieve in this summoning chamber";
        items[4] = "walls";
        items[5] = "The walls are made from black marble and they feel quite cold. A lots of spider webs are hanging on ceiling and walls like a tattered shrouds";
        items[6] = "floor";
        items[7] = "Somekind of markings are carved at the floor and they look like some sort of ritual scene";
        property = allocate(1);
        property[0] = "no_summon";
        set_not_out(1);
        set_light(0);
}

query_summon_circle() { return 1; }
query_startroom() { return 1; }