inherit "room/room";
string str;
object monster;
int i;

reset(arg) {
        i = random(20);

        str = "";
        switch(i) {
        case 0..1: str = "/wizards/rag/elf/monsters/hare"; break;
        case 2..4: str = "/wizards/rag/elf/monsters/snake"; break;
        case 5..7: str = "/wizards/rag/elf/monsters/fox"; break;
        case 8..9: str = "/wizards/rag/elf/monsters/deer"; break;
        case 10..13: str = "/wizards/rag/elf/monsters/wolf"; break;
        case 14..16: str = "/wizards/rag/elf/monsters/bear"; break;
        }

        if(!monster && str != "") {
         monster = clone_object(str);
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/e_c3");
        add_exit("north","/wizards/rag/elf/e_c4");
        add_exit("northeast","/wizards/rag/elf/e_c5");
        add_exit("west","/wizards/rag/elf/e_d3");
        add_exit("east","/wizards/rag/elf/e_d5");
        add_exit("southwest","/wizards/rag/elf/e_e4");
        add_exit("south","/wizards/rag/elf/e_e5");
        add_exit("southeast","/wizards/rag/elf/e_e6");

        short_desc = "By a pond";
        long_desc = "The forest seems to get a bit darker. The birds have stopped\n"+
                        "singing and you can hear something growling in the bushes.\n"+
                        "The trees are covered with moss and gnarls. Only a little light\n"+
                        "is getting past the old trees. There aren't any signs of hunters\n"+
                        "or other living beings. There is a shimmering pond to the southeast.\n";

        items = allocate(4);
        items[0] = "trees";
        items[1] = "You see sturdy lookings oaks and dark spruces";
        items[2] = "bushes";
        items[3] = "You see bushes full of berries";
}
