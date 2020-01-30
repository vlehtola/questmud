inherit "room/room";

reset(arg) {

        if(!present("orc")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }

        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_c3");

        short_desc = "In a dead end";
        long_desc = "A tunnel leads back to west. Grunts and shouts can be heard\n"+
                        "from a distance. The walls seem to be carved very roughly but\n"+
                        "efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
