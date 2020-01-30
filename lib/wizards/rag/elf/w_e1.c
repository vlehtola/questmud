inherit "room/room";

reset(arg) {

        if(!present("troll")) {
                move_object(clone_object("/wizards/rag/elf/monsters/troll"), this_object());
        }

        if(arg) return;

        add_exit("north","/wizards/rag/elf/w_d1");
        add_exit("southeast","/wizards/rag/elf/w_f1");

        short_desc = "In the cave";
        long_desc = "Tunnels continue to north and southeast. Grunts and shouts\n"+
                        "can be heard from a distance. The walls seem to be carved very\n"+
                        "roughly but efficiently. The air is damp and smells like death.\n"+
                        "An enourmous pile of food is rotting here.\n";

        items = allocate(4);
        items[0] = "pile";
        items[1] = "You see different kinds of meat and big barrels of ale";
        items[2] = "food";
        items[3] = "You see different kinds of meat and big barrels of ale";

        set_not_out();
}
