inherit "room/room";

reset(arg) {
        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_e2");
        add_exit("north","/wizards/rag/elf/w_d4");
        add_exit("northeast","/wizards/rag/elf/w_d5");
        add_exit("southeast","/wizards/rag/elf/w_f4");

        short_desc = "Crossing of tunnels";
        long_desc = "Tunnels leave to many directions here. Grunts and shouts can be\n"+
                        "heard from some of the tunnels and echoes from others. This could\n"+
                        "be quite a maze. The air is damp and it smells of death and decay.\n";

        set_not_out();
}
