/* Tahe mobi? */
inherit "room/room";

reset (arg) {

        add_exit("east","temple5");
        short_desc = "A small corridor in temple";
        long_desc = "In these parts of temple aren't much of decorations\n"+
                    "on walls ecpects couple of burned torches both side of\n"+
                    "wall. The floor looks like it never been washed and lots\n"+
                    "of dust is on the floor. The ceiling is collased here.\n";
        set_not_out(1);
        set_light(1);
}
