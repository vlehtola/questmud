inherit "room/room";
reset (arg) {
    if(arg) return;
        short_desc = "Front of the chicken coops";
        long_desc = "The coops are made of thick chicken wire with small holes in it.\n"+
                    "Lots of small barrels full of grain and water have been placed in front\n"+
                    "of the coops.\n";
add_exit("south","room6");
add_exit("east","room4");
add_exit("southwest","room5");
items = allocate(4);
items[0] = "barrels";
items[1] = "The barrels are filled with grain and water, food for chickens";
}

