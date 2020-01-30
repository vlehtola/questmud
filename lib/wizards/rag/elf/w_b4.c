inherit "room/room";
object block, block2;

reset(arg) {
        if(!block) {
                block = clone_object("/wizards/rag/elf/monsters/orc_nw");
                move_object(block, this_object());
        }
        if(!block2) {
                block2 = clone_object("/wizards/rag/elf/monsters/orc_ne");
                move_object(block2, this_object());
        }
        if(!present("orc 3")) {
                move_object(clone_object("/wizards/rag/elf/monsters/orc"), this_object());
        }


        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/w_a2");
        add_exit("northeast","/wizards/rag/elf/w_a3");
        add_exit("south","/wizards/rag/elf/w_c3");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to northwest, northeast and south. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n"+
                        "This part of the cave seems to be guarded heavily.\n";

        set_not_out();
}
