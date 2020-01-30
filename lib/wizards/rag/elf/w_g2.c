inherit "room/room";
string str;

reset(arg) {
        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/w_f7");
        add_exit("east","/wizards/rag/elf/room2");

        short_desc = "A small path";
        long_desc = "A small path seems to leading from northwest\n"+
                        "to east. There are lots of different prints on the\n"+
                        "path. The forest is getting lighter and there are\n"+
                        "only a few trees growing here.\n";

        str = "You see prints made by different animals but you also notice\nprints made by heavy boots";
        items = allocate(4);
        items[0] = "prints";
        items[1] = str;
        items[2] = "path";
        items[3] = str;

}
