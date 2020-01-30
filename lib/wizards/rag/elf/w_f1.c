inherit "room/room";

reset(arg) {

        if(!present("orc")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }


        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/w_e1");
        add_exit("northeast","/wizards/rag/elf/w_e2");


        short_desc = "In the cave";
        long_desc = "Tunnels continue to northwest and northeast. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n";

        set_not_out();
}
