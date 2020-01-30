inherit "room/room";
reset(arg) {
    if(arg) return;
    add_exit("north","/wizards/siggy/area/unseen/uu23.c");
    add_exit("south","/wizards/siggy/area/unseen/uu28.c");
    add_exit("east","/wizards/siggy/area/unseen/uu27.c");
    add_exit("west","/wizards/siggy/area/unseen/uu25.c");
    set_not_out(3);
    short_desc = "A hall";
    long_desc = 
        "Same looking hall as the northern one. There seems to be no-one here.\n"
        + "Also here are three signs pointing east, south and west. South pointing\n" 
        + "sign says 'The Great leader of university, Jehu' and the rest two are\n"
        + "propably pointing to other leader figures of this old building.\n";
}




