inherit "room/room";
object hring;

reset(arg) {
        if(!hring) {
                hring = clone_object("/wizards/neophyte/city/monst/hring");
                move_object(hring, this_object());
        }
        if(arg) return;

        add_exit("south","temple3");

        short_desc = "A small chapel";
        long_desc = "You are standing on a floor listening prayers. Near the west\n"+
                    "wall is small altar which seem to glitter in the light. Walls are\n"+
                    "full of a pictures and images of historical events and a candle lamp\n"+
                    "made thousands of small crystal is hanging from the ceiling.\n";
               items = allocate(6);
               items[0] = "altar";
               items[1] = "This altar glitters with heavenly light";
               items[2] = "pictures";
               items[3] = "It represent a god of light and some unknow demon";
               items[4] = "lamp";
               items[5] = "when light hit is lamp start to shimmers with beautifull colours";
        set_not_out(3);
    set_light(3);
}
