inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("northeast","outmap: 60 125");
        add_exit("north","outmap: 59 125");
        add_exit("northwest","outmap: 58 125");
        add_exit("west","outmap: 59 124");
        add_exit("enter","room1");
        short_desc = "A front of Cathedral of Chaos";
        long_desc = "A front of the cathedral of chaos, which is the place where all "+
        "warlock's come to study and gain knowledge in their dark rituals. The cathedral is builded from somekind of black marble what gives the feeling of darkness. "+
        "A loud screaming sounds can be heard time to time from the cathedral.\n";
        items = allocate(2);
        items[0] = "cathedral";
        items[1] = "The cathedral looks massive";
        property = allocate(1);
property[0] = "no_summon";
}

init() {
::init();
add_action("enter", "enter");
}

enter() {
if(!this_player()->query_guild_level("Warlocks")) {
write("You feel too puny to enter that place.\n");
return 1;
}
}

        G     G
        |     |
        4  S  8
        |  |  |
      G-3  5  7-G
        |  |  |
        2--1--6
           |
           E