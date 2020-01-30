inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "At the small path in forest";
        long_desc = "This is a small path that goes all the way to the beach.\n"+
                    "Stunted trees grow all around you, they even form a little\n"+
                    "forest around here. The view is quite ugly.\n";
    add_exit("south","/wizards/neophyte/forest/room5");
    add_exit("southwest","/wizards/neophyte/forest/room7");
}
