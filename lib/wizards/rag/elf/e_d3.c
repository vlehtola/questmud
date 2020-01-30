inherit "room/room";
string str;
object monster;
int i;

init() {
        add_action("climb", "climb");
        ::init();
}

reset(arg) {
        i = random(20);

        str = "";
        switch(i) {
        case 0: str = "/wizards/rag/elf/monsters/hare"; break;
        case 1..3: str = "/wizards/rag/elf/monsters/snake"; break;
        case 4..6: str = "/wizards/rag/elf/monsters/fox"; break;
        case 7..10: str = "/wizards/rag/elf/monsters/deer"; break;
        case 11..13: str = "/wizards/rag/elf/monsters/wolf"; break;
        case 14..15: str = "/wizards/rag/elf/monsters/bear"; break;
        }

        if(!monster && str != "") {
         monster = clone_object(str);
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/e_c2");
        add_exit("north","/wizards/rag/elf/e_c3");
        add_exit("northeast","/wizards/rag/elf/e_c4");
        add_exit("west","/wizards/rag/elf/e_d2");
        add_exit("east","/wizards/rag/elf/e_d4");
        add_exit("southwest","/wizards/rag/elf/e_e3");
        add_exit("south","/wizards/rag/elf/e_e4");
        add_exit("southeast","/wizards/rag/elf/e_e5");

        short_desc = "Deep in the forest";
        long_desc = "This forest looks very peaceful. There are beautiful trees\n"+
                        "and bushes covering the area. Birds are singing and you hear\n"+
                        "different animals scurrying around the forest. There aren't\n"+
                        "any signs of hostile animals or monsters. Actually, the forest\n"+
                        "seems perfectly calm. There are very large oak trees growing\n"+
                        "here.\n";

        items = allocate(6);
        items[0] = "trees";
        items[1] = "The massive oaks are entwined together";
        items[2] = "bushes";
        items[3] = "You see bushes full of berries";
        items[4] = "oaks";
        items[5] = items[1];
}

climb(str) {
        write("You try to climb the oaks, but the they are too thick\n"+
                "and the branches just block your path.\n");
        say(this_player()->query_name()+" tries to climb to oaks, but doesn't succeed.\n");
        return 1;
}
