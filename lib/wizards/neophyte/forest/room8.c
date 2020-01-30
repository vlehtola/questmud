inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "At the small path in forest";
long_desc = "You are walking in the sandy path. There are only couple of wisps\n"+
            "growing here. The view is quite nice in here, a beach opens in front of you.\n";
    add_exit("north","/wizards/neophyte/forest/room7");
    add_exit("southwest","/wizards/neophyte/forest/room9");
    add_exit("southeast","/wizards/neophyte/forest/room11");
}
