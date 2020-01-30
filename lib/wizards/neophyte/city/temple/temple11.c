inherit "room/room";

reset (arg) {

    add_exit("north","study1");
    add_exit("south","temple10");
    add_exit("west","temple12");
    add_exit("east","temple13");
        short_desc = "A small corridor in temple";
        long_desc = "The small corridor front of the class rooms. Class rooms\n"+
                    "are full and the teaching is currently on. The walls are full\n"+
                    "of different paintings. A large bookshelf is placed next to the\n"+
                    "wall.\n";
        set_not_out(1);
        set_light(3);
}
