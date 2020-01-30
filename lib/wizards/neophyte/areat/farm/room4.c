inherit "room/room";
reset (arg) {
    if(arg) return;
        short_desc = "Courtyard";
        long_desc = "On a courtyard of the farm. There are apple and cherry trees around this\n"+
                    "area. Their blossoms look nice and bees are collecting honey from them.\n"+
                    "The road divides into two different roads, the one that goes west to the\n"+
                    "chicken coops and to the southeast, where are the pig pens. A small path\n"+
                    "leads to the east.\n";
add_exit("north","room2");
add_exit("south","room7");
add_exit("west","room3");
add_exit("southeast","room8");
add_exit("east", "room13");
items = allocate(4);
items[0] = "trees";
items[1] = "Beautiful trees with lots of flowers on the branches";
items[2] = "road";
items[3] = "A muddy road that divides to smaller road";
}

