inherit "room/room";
object mon;

reset(arg) {

        if(arg) return;

        if(!mon) {
                mon = clone_object("/wizards/rag/elf/monsters/salin");
                move_object(mon, this_object());
        }


        add_exit("north","/wizards/rag/elf/u_c4");
        add_exit("west","/wizards/rag/elf/u_d3");
        add_exit("southwest","/wizards/rag/elf/u_e4");

        short_desc = "Up in the tree";
        long_desc =     "The elven treehouse, or 'flet', is built with great skill.\n"+
                        "Beautiful carvings and ornaments are on the walls, the floor\n"+
                        "and the slender fences which prevent you from falling. You\n"+
                        "are standing on a balcony which is surrounding great oaks.\n"+
                        "There is a doorway leading west and deeper into the oaks.\n"+
                        "You can almost see the whole forest from here.\n";
}
