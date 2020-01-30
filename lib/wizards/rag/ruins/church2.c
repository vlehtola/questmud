inherit "room/room";

init() {
        add_action("up","up");
        add_action("up","climb");
        ::init();
}

reset(arg) {
        if(arg) return;
        add_exit("east","/wizards/rag/ruins/church1");

        short_desc = "Under the bell tower";
        long_desc =     "The bell tower looks much higher than you've imagined. The stone\n"+
                        "structures look durable, but all wooden constructions have been\n"+
                        "burned. Some kind of a platform seems to be about 30 feet above\n"+
                        "your head. The remainings of wooden stairs can be seen some 15\n"+
                        "feet above you. The floorboards are badly charred.\n";

	set_not_out(1);
        items = allocate(2);
        items[0] = "stairs";
        items[1] = "Too bad that the stairs are burned, otherwise you could have just\n"+
                   "walked up. If you only had something to climb on..";

        set_sound(29+random(6),"You hear the pouring rain and the raging thunder.\n");
}

up() {
        object ob;
        ob = present("ladders",this_object());
        if(ob) {
                write("You reach the stairs using the ladders.\n");
                say(this_player()->query_name()+" reaches the stairs using the ladders.\n");
                this_player()->move_player("up#/wizards/rag/ruins/tower");
                return 1;
        } else {
                write("You can't reach the burned stairs.\n");
                return 1;
        }
}
        
