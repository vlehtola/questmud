inherit "room/room";
string str;
object monster;
int i;

reset(arg) {
        i = random(20);

        str = "";
        switch(i) {
        case 0..1: str = "/wizards/rag/elf/monsters/snake"; break;
        case 2..3: str = "/wizards/rag/elf/monsters/fox"; break;
        case 4..6: str = "/wizards/rag/elf/monsters/deer"; break;
        case 7..9: str = "/wizards/rag/elf/monsters/wolf"; break;
        case 10..14: str = "/wizards/rag/elf/monsters/bear"; break;
        }

        if(!monster && str != "") {
         monster = clone_object(str);
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("east","/wizards/rag/elf/e_a2");
        add_exit("southwest","/wizards/rag/elf/e_b1");
        add_exit("south","/wizards/rag/elf/e_b2");
        add_exit("southeast","/wizards/rag/elf/e_b3");

        short_desc = "Deep in the dark forest";
        long_desc = "The forest seems to get a bit darker. The birds have stopped\n"+
                        "singing and you can hear something growling in the bushes.\n"+
                        "The trees are covered with moss and gnarls. Only a little light\n"+
                        "is getting past the old trees. There aren't any signs of hunters\n"+
                        "or other living beings.\n";

        items = allocate(4);
        items[0] = "trees";
        items[1] = "You see sturdy lookings oaks and dark spruces";
        items[2] = "bushes";
        items[3] = "You see bushes full of berries";
}
