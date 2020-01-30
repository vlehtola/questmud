inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("east","/wizards/neophyte/workroom");
        add_exit("castle","/wizards/neophyte/castle/entrance");
        add_exit("farm","/wizards/neophyte/farm/room1");
        add_exit("forest","/wizards/neophyte/forest/room1");
        add_exit("city","/wizards/neophyte/city/entrance");
        short_desc = "Area portal";
        long_desc = "Area portal room\n";
        property = allocate(1);
        property[0] = "no_summon";
        set_not_out(1);
        set_light(0);
}
