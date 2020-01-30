inherit "room/room";
object mon;

reset(arg) {

        if(arg) return;

        if(!mon) {
                mon = clone_object("/wizards/rag/elf/monsters/finlos");
                move_object(mon, this_object());
        }

        add_exit("west","/wizards/rag/elf/u_c1");

        short_desc = "Inside the mighty oaks";
        long_desc =     "This part of the flet is used for sleeping and\n"+
                        "relaxing. There are blankets and pillows laying\n"+
                        "on the floor. Although there is no roof above your\n"+
                        "head, this place seems warm and cosy. There is a\n"+
                        "a big table next to the oaks. The oaks block you\n"+
                        "way to other areas that the oaks hide.\n";

        items = allocate(4);
        items[0] = "table";
        items[1] = "There are some books on the table";
        items[2] = "books";
        items[3] = "The books are written about some ancient battles";
}
