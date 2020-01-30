inherit "room/room";

reset(arg) {
        if(!present("troll")) {
                move_object(clone_object("/wizards/rag/elf/monsters/troll"), this_object());
        }
        if(arg) return;

        add_exit("southwest","/wizards/rag/elf/w_b2");
        add_exit("southeast","/wizards/rag/elf/w_b4");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to southwest and southeast. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
