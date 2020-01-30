inherit "room/room";

reset(arg) {

        if(!present("orc")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }

        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_d1");
        add_exit("southeast","/wizards/rag/elf/w_e2");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to west and southeast. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
