inherit "room/room";

reset (arg) {

    add_exit("north","temple11");
    add_exit("south","temple9");
        short_desc = "A small corridor in temple";
        long_desc = "This part the temple is based on their studing. A class-rooms\n"+
                    "can be seen in the distance. A rags are laying on the floor they\n"+
                    "must be the yonger student, cause the elders ones dont throw their\n"+
                    "clothes on the floor.\n";
        set_not_out(1);
        set_light(2);
}
