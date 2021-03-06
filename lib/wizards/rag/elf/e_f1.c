inherit "room/room";
string str;
object monster;
int i;

reset(arg) {
        i = random(15);

        str = "";
        switch(i) {
        case 0..3: str = "/wizards/rag/elf/monsters/hare"; break;
        case 4..6: str = "/wizards/rag/elf/monsters/snake"; break;
        case 7..8: str = "/wizards/rag/elf/monsters/fox"; break;
        case 9..10: str = "/wizards/rag/elf/monsters/deer"; break;
        case 11: str = "/wizards/rag/elf/monsters/wolf"; break;
        case 12: str = "/wizards/rag/elf/monsters/bear"; break;
        }

        if(!monster && str != "") {
         monster = clone_object(str);
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("north","/wizards/rag/elf/e_e1");
        add_exit("northeast","/wizards/rag/elf/e_e2");
        add_exit("east","/wizards/rag/elf/e_f2");
        add_exit("southwest","/wizards/rag/elf/e_g1");
        add_exit("south","/wizards/rag/elf/e_g2");
        add_exit("southeast","/wizards/rag/elf/e_g3");

        short_desc = "In the forest";
        long_desc = "This forest looks very peaceful. There are beautiful trees\n"+
                        "and bushes covering the area. Birds are singing and you hear\n"+
                        "different animals scurrying around the forest. There aren't\n"+
                        "any signs of hostile animals or monsters. Actually, the forest\n"+
                        "seems perfectly calm.\n";

        items = allocate(4);
        items[0] = "trees";
        items[1] = "You see sturdy lookings oaks and slender birches";
        items[2] = "bushes";
        items[3] = "You see bushes full of berries";
}
