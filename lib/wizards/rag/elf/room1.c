inherit "room/room";

reset(arg) {
        add_exit("north","/wizards/rag/elf/room2");
        add_exit("out","outmap: 165 147");

        short_desc = "Beginning of a forest";
        long_desc = "Beautiful trees surround a small path leading north.\n"+
                        "Birds are singing and the sun is shining. Small\n"+
                        "animals run around the path, but never cross it.\n";

        items = allocate(2);
        items[0] = "trees";
        items[1] = "You see sturdy lookings oaks and slender birches";
}
