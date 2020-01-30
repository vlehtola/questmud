inherit "room/room";

reset(arg) {
        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_b1");
        add_exit("northeast","/wizards/rag/elf/w_a2");
        add_exit("east","/wizards/rag/elf/w_b3");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to west, northeast and east. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
