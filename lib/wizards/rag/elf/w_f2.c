inherit "room/room";

reset(arg) {

        if(arg) return;

        add_exit("north","/wizards/rag/elf/w_e2");
        add_exit("southeast","/wizards/rag/elf/w_g1");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to north and southeast. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
