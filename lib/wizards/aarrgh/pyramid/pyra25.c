inherit "room/room";

reset(arg) {
            add_exit("south", "/wizards/aarrgh/pyramid/pyra28");
            add_exit("north", "/wizards/aarrgh/pyramid/pyra24");
            add_exit("west",  "/wizards/aarrgh/pyramid/pyra26");
            add_exit("southwest", "/wizards/aarrgh/pyramid/pyra27");
            add_exit("southeast", "/wizards/aarrgh/pyramid/pyra29");
            add_exit("east", "/wizards/aarrgh/pyramid/pyra30");
            short_desc = "In the Pyramid";
            long_desc = "You are in the second section of the pyramid.\n" +
                        "This section seems to be much deeper than the.\n"+
                        "first part. You begin to wonder are there\n"+
                        "any way to get out from this horrible place.\n";
 }


