inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "At the small path in forest";
        long_desc = "You are walking on a sandy path. Trees in here are\n"+
                "a lot smaller and stunted than before, maybe it's\n"+
                "because of the sandy ground which sure isen't a perfect\n"+
                "growing base.\n";
    add_exit("north","/wizards/neophyte/forest/room6");
    add_exit("northeast","/wizards/neophyte/forest/room4");
}
