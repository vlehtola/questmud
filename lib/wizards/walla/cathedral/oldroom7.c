inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","room8");
        add_exit("south","room6");
        add_exit("east","room7");
        short_desc = "Short desc";
        long_desc = "Long desc\n";
        items = allocate(2);
        items[0] = "item";
        items[1] = "item desc";
        property = allocate(1);
property[0] = "no_summon";
}
