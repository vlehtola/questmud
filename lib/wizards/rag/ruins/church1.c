inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("north","/wizards/rag/ruins/church3");
        add_exit("west","/wizards/rag/ruins/church2");
        add_exit("south","/wizards/rag/ruins/ruins_s");

        short_desc = "Entrance to the church";
        long_desc =     "The entrance hall to the church is very high. Beautiful arches\n"+
                        "loom high above you. Unfortunately, you are too late to see\n"+
                        "the church in it's most glorious times. There aren't any decorations\n"+
                        "here, everything is robbed or defiled. The floorboards look\n"+
                        "dangerously charred. A corridor leads west to the bell tower.\n"+
                        "The main hall of the church is located to the north.\n";

	set_not_out(1);
        set_sound(23+random(6),"You hear the pouring rain and the raging thunder.\n");
}
