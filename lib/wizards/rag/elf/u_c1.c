inherit "room/room";

reset(arg) {
        if(!present("elf")) {
                move_object(clone_object("/wizards/rag/elf/monsters/elf"), this_object());
        }

        if(arg) return;

        add_exit("northeast","/wizards/rag/elf/u_b2");
        add_exit("east","/wizards/rag/elf/u_c2");
        add_exit("south","/wizards/rag/elf/u_d1");

        short_desc = "Up in the tree";
        long_desc =     "The elven treehouse, or 'flet', is built with great skill.\n"+
                        "Beautiful carvings and ornaments are on the walls, the floor\n"+
                        "and the slender fences which prevent you from falling. You\n"+
                        "are standing on a balcony which is surrounding great oaks.\n"+
                        "There is a doorway leading east and deeper into the oaks.\n"+
                        "You can almost see the whole forest from here.\n";
}