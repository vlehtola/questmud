inherit "room/room";

init() {
        add_action("enter","enter");
        ::init();
}

reset(arg) {
        if(arg) return;
        add_exit("south","/wizards/rag/ruins/ruins_se");

        short_desc = "Next to the church";
        long_desc =     "An old shack is located next to the church. There is\n"+
                        "a wooden fence around the shack. The wall surrounding\n"+
                        "the church is connected to the wall of the church so\n"+
                        "that you can't go to the back of the church. Some tools\n"+
                        "are laying in front of the shack.\n";                  

        items = allocate(10);
        items[0] = "church";
        items[1] = "The church is heavily burned and totally ruined";
        items[2] = "wall";
        items[3] = "The wall is very old but it's still very sturdy";
        items[4] = "shack";
        items[5] = "The shack might crash down any minute now, but you might have\n"+
                        "just enough time to enter and exit it safely";
        items[6] = "tools";
        items[7] = "You see some broken tools, like shovels and hammers";
        items[8] = "fence";
        items[9] = "The fence doesn't really give any protection from intruders";

        set_sound(16+random(6),"Rain pours heavily down from the sky.\n");
        set_sound(22+random(6),"Thunder and lightning rage over the church.\n");
}

enter(str) {
        if (str == "shack") {
                write("You climb over the fence, open the shack's door and enter the shack.\n");
                say(this_player()->query_name()+ " climbs over the fence, opens the shack's"+
                " door and enters the shack.\n");
                this_player()->move_player("shack#/wizards/rag/ruins/shack");
                return 1;
        }
        write("Enter what?\n");
        return 1;
}
