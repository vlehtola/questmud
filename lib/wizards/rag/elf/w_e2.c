inherit "room/room";

reset(arg) {

        if(!present("orc")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }

        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/w_d2");
        add_exit("southwest","/wizards/rag/elf/w_f1");
        add_exit("east","/wizards/rag/elf/w_e3");
        add_exit("south","/wizards/rag/elf/w_f2");

        short_desc = "More tunnels";
        long_desc = "Even more corriders spread out to different directions.\n"+
                        "The cave seems a lot bigger than you first thought by the\n"+
                        "size of the hills. The air smells of flesh and sweat. There\n"+
                        "aren't any loose rocks here, so this tunnel must be frequently\n"+
                        "used.\n";

        set_not_out();
}
