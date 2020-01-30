inherit "room/room";

reset (arg) {

    add_exit("east","temple9");
    add_exit("south","temple7");
        short_desc = "A small corridor in temple";
        long_desc = "The corridor takes a sharp turn to east and still continuos\n"+
                    "deeper inside the temple. On the wall is a single torch hanging\n"+
                    "on the holster. The corridors are echoing all the noises that are\n"+
                    "coming deeper inside the temple.\n";
        set_not_out(1);
        set_light(1);
}
