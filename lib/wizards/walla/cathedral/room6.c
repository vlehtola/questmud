
inherit "room/room";
 
reset(arg) {
        if(arg) return;
        add_exit("south","room7");
        add_exit("west","room1");
        short_desc = "In a faintly lit corridor";
        long_desc = "The cold stone floor is covered by a clingy oily film, that drips from one of the stone walls, making the ground \n" +
                    "very slippery. In an alcove, you see a six-foot nightmare of bone. A horned skull on a human spine over the \n" +
                    "shoulders of a bear. Dried blood flasks out of the joints and crevices, and empty sockets stare right at you,\n" +
                    "following you. The stench has made your nose pretty much numb of any smell here by now. \n";
        items = allocate(2);
        items[0] = "item";
        items[1] = "item desc";
        property = allocate(1);
property[0] = "no_summon";
}
 


