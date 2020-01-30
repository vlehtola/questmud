inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "A dead end";
        long_desc = "The forest get way too thick to move anylonger here.\n"+
                    "In here is only one way out, to the north.\n";
    add_exit("north","/wizards/neophyte/forest/room17");
}
