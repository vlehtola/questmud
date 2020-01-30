inherit "room/room";

reset(arg) {
        if(!present("elf")) {
                move_object(clone_object("/wizards/rag/elf/monsters/elf"), this_object());
        }

        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/u_b3");
        add_exit("south","/wizards/rag/elf/u_d4");

        short_desc = "Up in the tree";
        long_desc =     "The elven treehouse, or 'flet', is built with great skill.\n"+
                        "Beautiful carvings and ornaments are on the walls, the floor\n"+
                        "and the slender fences which prevent you from falling. You\n"+
                        "are standing on a balcony which is surrounding great oaks.\n"+
                        "There seems to be people living within the oaks, but you can't\n"+
                        "enter here. You can almost see the whole forest from here.\n";
}
