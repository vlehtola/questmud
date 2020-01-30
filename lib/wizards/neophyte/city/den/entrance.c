inherit "room/room";

reset(arg) {
add_exit("out","/wizards/duncan/island/virtual_map: 27 13");
add_exit("northwest","room5");
        add_exit("northeast","room2");
        add_exit("southwest","room4");
        add_exit("southeast","room3");
short_desc = "A smelly cave";
long_desc = "Cavern walls have been dug with rush and age hasn't corroded the rock.\n"+
            "Smell is quite good, almost too good to be a wolfrider hideout. Almost in\n"+
            "the center of the cavern is a wooden table and there are some cards on it.\n"+
            "The floor of the cavern has been slightly worn because of high usage and\n"+
            "there are also lots of animal droppings.\n";

set_not_out(2);
 items = allocate(4);
 items[0] = "table";
 items[1] = "A wooden table, which isn't the sturdiest one you have seen";
 items[2] = "floor";
 items[3] = "The floor is covered with animal steps and droppings";

}
