inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "A strange field";
        long_desc = "This is a quite small field growing hay and wheat. A ditch is coming\n"+
                    "here from another field and continues forward. The ground feels funny\n"+
                    "cause there arent any signs of wildlife stepped on.\n";
        add_exit("south", "room15");
        add_exit("west", "room13");
        add_exit("east", "room8");
        }
