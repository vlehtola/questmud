inherit "room/room";
reset(arg) {
        if(arg) return;
        short_desc = "A shady shore";
        long_desc = "This is A quite big field where people used to grow wheat.\n"+
                    "It's a sad view because the ground is now filled with rotten hay and corpses.\n"+
                    "A small stream floats through the field and the path, the water is muddy and\n"+
                    "filled with straws and entrails.\n";
        add_exit("northwest", "room18");
        add_exit("northeast", "room11");
        set_water(2);
                items = allocate(6);
		        items[0] = "ground";
		        items[1] = "The ground is filled with rotten hay and decayed corpses";
		        items[2] = "stream";
		        items[3] = "The water in stream looks dirty";
        }
