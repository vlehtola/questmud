inherit "room/room";
reset (arg) {
                if(arg) return;
        add_exit("north","stairs2");
    add_exit("west","temple2");
    add_exit("east","temple26");
        short_desc = "A small corridor in temple";
        long_desc = "The dark and gloomy corridor inside the temple.\n"+
                    "On the floor is small pool of blood and parts of clothes,\n"+
                    "looks like in here have been a fig. At the wall is torch hanging\n"+
                    "from the holder. To the north is stairs.\n";
        set_not_out(1);
        set_light(1);
}
