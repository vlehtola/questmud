inherit "room/room";

reset(arg) {
        add_exit("up","hall");
        add_exit("down","tower1");
short_desc = "Stairs going up";
long_desc = "You are approximately at the second floor of the tower. A steel stairs\n"+
            "has been built in here, offering an easy way upwards, to the top of the\n"+
            "tower. On the walls are lots of pictures, with golden frames, representing\n"+
            "the former kings.\n";
    items = allocate(4);
    items[0] = "pictures";
    items[1] = "All of them represent former kings";
    items[2] = "stairs";
    items[3] = "The steel stairs are leading upwards, to the top of the tower";

set_not_out(1);
}
