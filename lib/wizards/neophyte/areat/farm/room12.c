inherit "room/room";
reset (arg) {
                                if(!present("pig")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/pig"),this_object());
                                }
                                if(!present("pig 2")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/pig"),this_object());
                                }
                                if(!present("pig 3")) {
                                move_object(clone_object("/wizards/neophyte/areat/farm/monst/pig"),this_object());
                                }
    if(arg) return;
        short_desc = "Inside the pig pen";
        long_desc = "The ground of pig pen is covered with several mud pools and\n"+
                    "food leftovers. Smell in here is very strong. The edges of pen\n"+
                    "are boarded with wooden fence. There are couple of food tubs\n"+
                    "beside the fence.\n";
add_exit("north","room8");
set_not_out(1);
set_light(1);
items = allocate(4);
items[0] = "pool";
items[1] = "Small pool of mud";
items[2] = "leftovers";
items[3] = "On the ground is piles of food leftovers, apples and so on";
}

