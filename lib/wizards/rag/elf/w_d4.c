inherit "room/room";

reset(arg) {
        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_d3");
        add_exit("south","/wizards/rag/elf/w_e3");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to west and south. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
