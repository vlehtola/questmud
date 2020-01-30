inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "A muddy trail inside the goblin village";
        long_desc = "This trail looks quite slender. The ground is full of small\n"+
                    "footprints which are going deeper in the village. Beside the\n"+
                    "trail is couple of small bushes, they are full of berries.\n";
        add_exit("northwest", "entrance");
        add_exit("southwest", "room2");
        add_exit("southeast", "room6");
        items = allocate(4);
        items[0] = "bushes";
        items[1] = "The bushes are full of berries, maybe a blackberries";
        items[2] = "ground";
        items[3] = "It is full of small footprints, smaller then average human prints";
        }
