inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "Entrance to goblin village";
        long_desc = "This look like a clearing but so small to be good camping place.\n"+
                    "A small trails are starting to go different directions, the on at\n"+
                    "southeast looks much more to be used, cause it is full of footprints.\n"+
                    "A couple of symbols are drawed on the surface of tree.\n";
        add_exit("northwest", "room11");
        add_exit("northeast", "room7");
        add_exit("southeast", "room1");
        add_exit("southwest", "room16");
        }
