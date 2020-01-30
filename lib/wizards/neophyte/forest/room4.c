inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Crossing of the paths";
        long_desc = "You are at a crossing of the paths. In here the paths starts\n"+
                    "to go into different directions. To the south is a cave, where can\n"+
                    "be heard roaring sound.\n";
    add_exit("north","/wizards/neophyte/forest/room15");
    add_exit("south","/wizards/neophyte/forest/cave1");
    add_exit("northwest","/wizards/neophyte/forest/room3");
    add_exit("southwest","/wizards/neophyte/forest/room5");
            items = allocate(2);
                    items[0] = "paths";
                    items[1] = "The paths starts to separate and go to different place";
}
