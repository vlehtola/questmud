inherit "room/room";

reset (arg) {

    add_exit("north","temple10");
    add_exit("west","temple8");
        short_desc = "A small corridor in temple";
        long_desc = "This part of the temple looks much cleaner and\n"+
                    "actualy the floor doesn't look that dirty anymore.\n"+
                    "A nice candler is hanged to the ceiling. A shadows\n"+
                    "are moving on the floor.\n";
        set_not_out(1);
        set_light(1);
}
