inherit "room/room";

reset (arg) {

    add_exit("north","private1");
    add_exit("east","temple11");
        short_desc = "A small corridor in temple";
        long_desc = "The small corridor ends here. To the north is someone's\n"+
                    "private room. The rocks on the walls look lots like a marble\n"+
                    "A large painting is hanging from western side of the wall, under\n"+
                    "the painting is title called 'cheating the one'.\n";
        set_not_out(1);
        set_light(2);
}
