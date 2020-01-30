inherit "room/room";

reset(arg) {
        if(!present("elf")) {
                move_object(clone_object("/wizards/rag/elf/monsters/elf"), this_object());
        }

        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/u_d1");
        add_exit("north","/wizards/rag/elf/u_d2");
        add_exit("east","/wizards/rag/elf/u_e4");

        short_desc = "Up in the tree";
        long_desc =     "The elven treehouse, or 'flet', is built with great skill.\n"+
                        "Beautiful carvings and ornaments are on the walls, the floor\n"+
                        "and the slender fences which prevent you from falling. You\n"+
                        "are standing on a balcony which is surrounding great oaks.\n"+
                        "There is a doorway leading north and deeper into the oaks.\n"+
                        "You can almost see the whole forest from here.\n";
}
