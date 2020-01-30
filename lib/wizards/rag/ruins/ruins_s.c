inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/church1");
        add_exit("west","/wizards/rag/ruins/ruins_sw");
        add_exit("east","/wizards/rag/ruins/ruins_se");

        short_desc = "In front of the church";
        long_desc =     "A doorway leads north in to the church. The doors are burned\n"+
                        "and smashed to pieces. The bell tower is located at the south\n"+
                        "end of the church. It is wavering a bit, but it seems to stay\n"+
                        "in one piece. The surrounding wall is slightly blackened by\n"+
                        "fire. There are some muddy footprints leading to the church.\n";

        items = allocate(10);
        items[0] = "church";
        items[1] = "The church is heavily burned and totally ruined";
        items[2] = "wall";
        items[3] = "The wall is very old but it's still very sturdy";
        items[4] = "doors";
        items[5] = "A great force has ripped the doors to pieces";
        items[6] = "tower";
        items[7] = "You feel that the tower could collapse any second";
        items[8] = "footprints";
        items[9] = "The footprints look very strange, definetely not human";

        set_sound(16+random(6),"Rain pours heavily down from the sky.\n");
        set_sound(22+random(6),"Thunder and lightning rage over the church.\n");

}
