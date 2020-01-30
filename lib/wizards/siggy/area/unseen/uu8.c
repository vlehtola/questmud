inherit "room/room";
reset(arg) {
    if(arg) return;
    add_exit("up","/wizards/siggy/area/unseen/uu21.c");
    add_exit("south","/wizards/siggy/area/unseen/uu6.c");
    add_exit("southeast","/wizards/siggy/area/unseen/uu7.c");
    set_not_out(3);
    short_desc = "Stairs going up";
    long_desc = 
        "Long stairs leading up. Stairs, stairs, stairs, only stairs going up. The\n"
        + "stairs are made of marble as the whole floor of the first level as well.\n" 
        + "These stairs are in very good shape, and the cleaner has made marvelous\n"
        + "job. Strange crystal windows are reflecting light in your eyes.\n";
}




