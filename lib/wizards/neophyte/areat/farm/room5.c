inherit "room/room";
reset (arg) {
                                if(!present("rooster")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/rooster"),this_object());
                                }
                                if(!present("chicken")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/chicken"),this_object());
                                }
                                if(!present("chicken 2")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/chicken"),this_object());
                                }
                                if(!present("chicken 3")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/chicken"),this_object());
                                }
    if(arg) return;
        short_desc = "Inside the chicken coop";
        long_desc = "You are inside the chicken coop. The floor is covered with large holes,\n"+
                    "chicken shit and small piles of grain. There's a small log in the middle\n"+
                    "of the coop. Chickens nests have been built on it.\n";
add_exit("northeast","room3");
add_exit("south","room9");
set_not_out(1);
set_light(1);
items = allocate(4);
items[0] = "nest";
items[1] = "A nest made from straw, inside it is couple small white eggs";
items[2] = "logs";
items[3] = "On the logs are lots of chicken nets";
}

