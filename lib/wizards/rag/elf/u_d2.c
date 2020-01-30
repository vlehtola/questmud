inherit "room/room";

reset(arg) {

        if(arg) return;

        add_exit("south","/wizards/rag/elf/u_e3");

        short_desc = "Inside the mighty oaks";
        long_desc =     "This part of the flet is used for sleeping and\n"+
                        "relaxing. There are blankets and pillows laying\n"+
                        "on the floor. Although there is no roof above your\n"+
                        "head, this place seems warm and cosy. The oaks\n"+
                        "block you way to other areas that the oaks hide.\n";
}
