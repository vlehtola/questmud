inherit "room/room";
inherit "room/door";
object orc, mystic, troll;

reset(arg) {
        if(!mystic) {
         mystic = clone_object("/wizards/rag/elf/monsters/mystic");
         move_object(mystic, this_object());
        }
        if(!troll) {
         troll = clone_object("/wizards/rag/elf/monsters/troll_b");
         move_object(troll, this_object());
        }
        if(arg) return;

        if(!orc) {
         orc = clone_object("/wizards/rag/elf/monsters/gabrash");
         move_object(orc, this_object());
        }

        short_desc = "Orc commander's headquarters";
        long_desc = "This is the chamber of the orc commander. It looks like a normal\n"+
                    "cave, but there's a big table in the center the the chamber. Some\n"+
                    "candels are burning on the table. There are chests and barrels by\n"+
                    "the walls.\n";

        items = allocate(8);
        items[0] = "table";
        items[1] = "There's a map of the forest on the table";
        items[2] = "chests";
        items[3] = "They seem to be locked or empty";
        items[4] = "barrels";
        items[5] = "The barrels are full of ale";
        items[6] = "map";
        items[7] = "There are strange markings on the northwest side of the forest.\n"+
                "The orcs must have found something there";

        door_reset();
        set_door_label("oaken door reinforced with bronze",1);
        set_door_dir("south", "/wizards/rag/elf/w_a1",1);
        set_door_link("/wizards/rag/elf/w_a1",1);
        set_door_code("817",1);
        set_locked(1,1);

        set_not_out();
}

init() {
  ::init();
  door_init();
}
