inherit "room/room";
reset (arg) {
                                        if(!present("horse")) {
                                        move_object(clone_object("/wizards/neophyte/areat/farm/monst/horse"),this_object());
                                        }
                                        if(!present("horse 2")) {
                                        move_object(clone_object("/wizards/neophyte/areat/farm/monst/horse"),this_object());
                                        }
                                        if(!present("horse 3")) {
                                        move_object(clone_object("/wizards/neophyte/areat/farm/monst/horse"),this_object());
                                        }

    if(arg) return;
        short_desc = "Horse stable";
        long_desc = "Inside the horse stables. The walls are covered with horseshoes, whips\n"+
                    "and all sort of horseman equipments. A small bucket full of water is in\n"+
                    "front of the wall and near that are several piles of yellowish hay.\n";
add_exit("north","room7");
add_exit("west","room10");
set_not_out(1);
set_light(2);
items = allocate(4);
items[0] = "walls";
items[1] = "All sort of horseman equipments are hanging from the wall";
items[2] = "bucket";
items[3] = "A wooden bucket filled with water";
}

