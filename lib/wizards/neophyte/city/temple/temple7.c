inherit "room/room";

reset (arg) {

    add_exit("north","temple8");
    add_exit("southeast","temple6");
        short_desc = "A small corridor in temple";
        long_desc = "The dark corridor inside the temple. In here is quite\n"+
                    "moist. A waterdrips are dropping from the ceiling. Again\n"+
                    "the claw marks can be seen on the surface of floor.\n";
        set_not_out(1);
        set_light(1);
}
