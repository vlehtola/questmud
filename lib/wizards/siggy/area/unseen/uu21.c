inherit "room/room";
reset(arg) {
    if (arg) return;
    add_exit("up","/wizards/siggy/area/unseen/uu31.c");
    add_exit("down","/wizards/siggy/area/unseen/uu8.c");
    add_exit("south","/wizards/siggy/area/unseen/uu23.c");
    add_exit("southeast","/wizards/siggy/area/unseen/uu24.c");
    add_exit("southwest","/wizards/siggy/area/unseen/uu22.c");
    set_not_out(3);
    short_desc = "Stairs going up and down";
    long_desc = 
        "Long stairs leading upstairs and downstairs. This level is made for apprentices'\n"
        + "personal rooms and a single high wizard's office. Stairs are clean, but you\n" 
        + "think that this must be the level for the most stupid wizards or atleast the\n"
        + "the most freaky wizards, it's so funky.\n";
}




