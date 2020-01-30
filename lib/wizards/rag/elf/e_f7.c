inherit "room/room";
string str;
object monster;
int i;

reset(arg) {
        i = random(20);

        str = "";
        switch(i) {
        case 0: str = "/wizards/rag/elf/monsters/hare"; break;
        case 1..2: str = "/wizards/rag/elf/monsters/snake"; break;
        case 3..5: str = "/wizards/rag/elf/monsters/fox"; break;
        case 6..7: str = "/wizards/rag/elf/monsters/deer"; break;
        case 8..11: str = "/wizards/rag/elf/monsters/wolf"; break;
        case 12..14: str = "/wizards/rag/elf/monsters/bear"; break;
        }

        if(!monster && str != "") {
         monster = clone_object(str);
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/e_e6");
        add_exit("north","/wizards/rag/elf/e_e7");
        add_exit("northeast","/wizards/rag/elf/e_e8");
        add_exit("west","/wizards/rag/elf/e_f6");

        short_desc = "By a pond";
        long_desc = "The forest seems to get a bit darker. The birds have stopped\n"+
                        "singing and you can hear something growling in the bushes.\n"+
                        "The trees are covered with moss and gnarls. Only a little light\n"+
                        "is getting past the old trees. There aren't any signs of hunters\n"+
                        "or other living beings. There is a shimmering pond to the northwest.\n";

        items = allocate(4);
        items[0] = "trees";
        items[1] = "You see sturdy lookings oaks and dark spruces";
        items[2] = "bushes";
        items[3] = "You see bushes full of berries";
}
