inherit "room/room";
object farmer;
reset(arg) {
	        if(!farmer) {
	                farmer = clone_object("/wizards/neophyte/village/monst/goblinfarmer");
	                move_object(farmer, this_object());
	        }
        if(arg) return;
        short_desc = "A clearing middle of fields";
        long_desc = "A small clearing in the middle of the fields. The ground is growing\n"+
                    "hay and weeds. A medium sized shed built between four large still\n"+
                    "growing trees, and in the middle of the shed is a huge pole suppporting\n"+
                    "it's roof, the pole is quite decayed and there is a bird's nest made in\n"+
                    "the pole. The shed itself is full of drags and rusty scythes.\n";
        add_exit("north", "room14");
        }
