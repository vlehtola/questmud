inherit "room/room";

reset(arg) {
        if(!present("orc")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }
        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/w_e3");
        add_exit("east","/wizards/rag/elf/w_f5");

        short_desc = "In the cave";
        long_desc = "The cave gets darker and darker. The cave continues\n"+
                        "to northwest. You can still see some light coming from\n"+
                        "east. The air is damp and it smells of death and decay.\n"+
                        "The walls seem to be mined so this isn't a natural cave.\n";

        set_not_out();
}
