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
        case 6..8: str = "/wizards/rag/elf/monsters/deer"; break;
        case 9..10: str = "/wizards/rag/elf/monsters/wolf"; break;
        case 11..14: str = "/wizards/rag/elf/monsters/bear"; break;
        }

        if(!monster && str != "") {
         monster = clone_object(str);
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("northwest","/wizards/rag/elf/e_b3");
        add_exit("north","/wizards/rag/elf/e_b4");
        add_exit("northeast","/wizards/rag/elf/e_b5");
        add_exit("west","/wizards/rag/elf/e_c3");
        add_exit("east","/wizards/rag/elf/e_c5");
        add_exit("southwest","/wizards/rag/elf/e_d3");
        add_exit("south","/wizards/rag/elf/e_d4");
        add_exit("southeast","/wizards/rag/elf/e_d5");

        short_desc = "Deep in the forest";
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

        set_sound(30+random(30),"You hear someone walking above you.\n");
}
