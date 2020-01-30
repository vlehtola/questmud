inherit "room/room";

reset(arg) {
        if(arg) return;

        add_exit("north","/wizards/rag/elf/w_b4");
        add_exit("east","/wizards/rag/elf/w_c4");
        add_exit("south","/wizards/rag/elf/w_d5");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to north, east and south. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
