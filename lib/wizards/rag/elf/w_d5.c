inherit "room/room";

reset(arg) {

        if(!present("orc")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc_nw"), this_object());
        }

        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/w_c2");
        add_exit("north","/wizards/rag/elf/w_c3");
        add_exit("southwest","/wizards/rag/elf/w_e3");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to northwest, north and southwest. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
