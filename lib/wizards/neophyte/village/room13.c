inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "A big field";
        long_desc = "A big field growing delicant looking wheat. This field looks\n"+
                    "well taken care of. Almost overflowing ditch is coming here from\n"+
                    "the lake. In the ditch is lots of pikes to spawning.\n";
        add_exit("north", "hut7");
        add_exit("east", "room14");
        add_exit("south", "room11");
        set_water(2);
                items = allocate(6);
		        items[0] = "field";
		        items[1] = "Wheat is growing on the field";
		        items[2] = "ditch";
		        items[3] = "Looks like the water is coming to overflow anyminute from ditch";
        }
