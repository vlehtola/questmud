inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/ruins_e");
        add_exit("west","/wizards/rag/ruins/ruins_s");
        add_exit("southwest","/wizards/rag/ruins/entrance");

        short_desc = "At the gate";
        long_desc =     "A raging storm blocks you vision. The old church can be seen\n"+
                        "clearly now. It is burned and parts of it's walls have collapsed.\n"+
                        "A metal gate is torn out of the wall surrounding the church\n"+
                        "leaving behind only a big hole. The ground is also torched.\n";

        items = allocate(8);
        items[0] = "church";
        items[1] = "The church is heavily burned and totally ruined";
        items[2] = "wall";
        items[3] = "The wall is very old but it's still very sturdy. It is covered with vines";
        items[4] = "vines";
        items[5] = "The vines grow against the wall. They aren't strong enough to be climbed";
        items[6] = "gate";
        items[7] = "The gate is twisted and it has been torn down with great force";

        set_sound(16+random(6),"Rain pours heavily down from the sky.\n");
        set_sound(22+random(6),"Thunder and lightning rage over the church.\n");

}
