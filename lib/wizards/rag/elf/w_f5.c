inherit "room/room";
object monster;

reset(arg) {
        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_f4");
        add_exit("out","/wizards/rag/elf/w_f6");

        short_desc = "In the cave";
        long_desc = "You are standing at the entrance of the cave.\n"+
                        "Small bones are scattered around the cave. The air\n"+
                        "is damp and it smells of death and decay. The cave\n"+
                        "continues to west. Only a little light is coming from\n"+
                        "outside. Maybe you should turn back.\n";

        items = allocate(2);
        items[0] = "bones";
        items[1] = "These are bones of small animals";

        set_not_out();
}
