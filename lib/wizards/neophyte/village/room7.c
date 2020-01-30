inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "A small hill";
        long_desc = "A small hill growing grass and a few trees that are slowly dying because\n"+
                    "their roots are quite badly damaged. On the grounds is small steps made\n"+
                    "from small animals.\n";
        add_exit("north", "room8");
        add_exit("southwest", "entrance");
        }
