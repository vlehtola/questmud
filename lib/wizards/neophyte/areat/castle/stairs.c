inherit "room/room";

reset(arg) {
        add_exit("up","tower1");
        add_exit("south","inside2");
short_desc = "Stairs going up";
long_desc = "A steel stairs begins from here, leading up to the top of the tower.\n"+
            "The top of stairs can't be seen, because of the darkness. The dusty\n"+
            "steps on the stairs look fragile and old.\n";
set_not_out(1);
}
