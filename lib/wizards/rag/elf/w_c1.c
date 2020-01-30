inherit "room/room";

reset(arg) {
        if(!present("orc")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }

        if(arg) return;

        add_exit("north","/wizards/rag/elf/w_b1");
        add_exit("southeast","/wizards/rag/elf/w_d3");
        add_exit("southwest","/wizards/rag/elf/w_d1");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to north, southeast and southwest. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n"+
                        "This part of the cave seems to be guarded heavily.\n";

        set_not_out();
}
