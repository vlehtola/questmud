inherit "room/room";
reset (arg) {
                                if(!present("cow")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/cow"),this_object());
                                }
                                if(!present("cow 2")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/cow"),this_object());
                                }
                                if(!present("cow 3")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/cow"),this_object());
                                }
    if(arg) return;
        short_desc = "Cow field";
        long_desc = "The ground looks almost naked as everything but some small spots\n"+
                    "of grass have been eaten. A wooden fence is built in all corners\n"+
                    "of the field, maybe to prevent cows from fleeing.\n";
add_exit("north","room3");
add_exit("south","room10");
add_exit("east","room7");
items = allocate(4);
items[0] = "fence";
items[1] = "A wooden fence is built here";
items[2] = "grass";
items[3] = "There are only small piles of grass left on the ground";
}

