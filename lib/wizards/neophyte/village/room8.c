inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "A small field";
        long_desc = "A small field growing hay and weeds. A small stream is flowing into this\n"+
                    "Field from west. The air is very fresh here and the scent of weeds and\n"+
                    "flowers is strong in here.\n";
        add_exit("west", "room14");
        add_exit("south", "room7");
        }
