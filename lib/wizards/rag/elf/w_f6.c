inherit "room/room";
object monster, sign;

reset(arg) {
        if (!sign) {
         sign = clone_object("/wizards/rag/elf/objects/sign");
         move_object(sign, this_object());
        }

        if(!monster) {
         monster = clone_object("/wizards/rag/elf/monsters/wolf");
         move_object(monster, this_object());
        }

        if(arg) return;

        add_exit("cave","/wizards/rag/elf/w_f5");
        add_exit("east","/wizards/rag/elf/w_f7");

        short_desc = "At the hills";
        long_desc = "The hills start to rise here. They are covered with grass\n"+
                        "and flowers. There is an entrance to a dark cave here. A lot\n"+
                        "of footprints seem to be leading to the cave. There are also small\n"+
                        "blood splashes around the entrance.\n";
        items = allocate(4);
        items[0] = "cave";
        items[1] = "It's a very dark cave. Some grunts can be heard from within the cave";
        items[2] = "entrance";
        items[3] = "The entrance is a bit frightening";
}
