inherit "room/room";

reset(arg) {
        add_exit("north","inside1");
        add_exit("gate","entrance");
        add_exit("northwest","gtower2");
        add_exit("northeast","gtower10");
short_desc = "Under the castle gate";
long_desc = "A rusty gate is opened for visitors to come. The high castle walls surrounds\n"+
            "the castle, protecting the castle from raids. Lots of footprints are leading\n"+
            "to the small towers, located northwest and northeast.\n";
set_not_out(3);
items = allocate(4);
items[0] = "gate";
items[1] = "The rusty gate is opened";
}
