inherit "room/room";
int i;

init() {
        add_action("dive", "dive");
        ::init();
        i = 5+random(10);
        call_out("warning", i);
        call_out("undead", i+5+random(5));
}


reset(arg) {

        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/e_d4");
        add_exit("north","/wizards/rag/elf/e_d5");
        add_exit("northeast","/wizards/rag/elf/e_d6");
        add_exit("west","/wizards/rag/elf/e_e5");
        add_exit("east","/wizards/rag/elf/e_e7");
        add_exit("southwest","/wizards/rag/elf/e_f5");
        add_exit("south","/wizards/rag/elf/e_f6");
        add_exit("southeast","/wizards/rag/elf/e_f7");

        short_desc = "In the pond";
        long_desc = "You are standing in the middle of the pond. The water\n"+
                        "is quite cold. The water is not too deep and you stand\n"+
                        "here. You can see small fishes swimming in the bottom\n"+
                        "of the pond. The dark forest if looming over you in a\n"+
                        "very frightening way.\n";

        set_water(7);

        items = allocate(2);
        items[0] = "pond";
        items[1] = "Although you can stand here, there seems to be some\n"+
                        "deeper spots in the pond";
}

warning() {
        tell_room(this_object(),"You get the feeling that you should get out of the water.\n");
        return 1;
}

undead() {
        object room, players;
        int i;

        room = this_object();
        players = all_inventory(room);

        for(i = 0;i<sizeof(players);i++) {
                if(living(players[i])) {
                        if(!players[i]->query_npc()) {
                                tell_object(players[i],"You feel a cold hand around your ankle and sink to the bottom of the pond!\n");
                                players[i]->move_player("d#/wizards/rag/elf/bottom");
                                tell_room(room,players[i]->query_name()+" is suddenly pulled to the bottom of the pond!\n");
                        }
                }
        }
        return 1;
}

dive() {
        write("You dive deeper and deeper and reach the bottom of the pond.\n");
        say(this_player()->query_name()+" dives to the pond.\n");
        this_player()->move_player("down#/wizards/rag/elf/bottom");
        return 1;
}
