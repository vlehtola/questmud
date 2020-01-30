inherit "room/room";
string str;
object monster;
int i;

init() {
        add_action("climb", "climb");
        ::init();
}

reset(arg) {
        i = random(18);

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

        add_exit("northwest","/wizards/rag/elf/e_d2");
        add_exit("north","/wizards/rag/elf/e_d3");
        add_exit("northeast","/wizards/rag/elf/e_d3");
        add_exit("west","/wizards/rag/elf/e_e3");
        add_exit("east","/wizards/rag/elf/e_e5");
        add_exit("southwest","/wizards/rag/elf/e_f3");
        add_exit("south","/wizards/rag/elf/e_f4");
        add_exit("southeast","/wizards/rag/elf/e_f5");
        

        short_desc = "Deep in the forest";
        long_desc = "This forest looks very peaceful. There are beautiful trees\n"+
                        "and bushes covering the area. Birds are singing and you hear\n"+
                        "different animals scurrying around the forest. There aren't\n"+
                        "any signs of hostile animals or monsters. Actually, the forest\n"+
                        "seems perfectly calm. There is a very large oak here.\n";

        items = allocate(6);
        items[0] = "trees";
        items[1] = "You see sturdy lookings oaks and dark spruces.";
        items[2] = "bushes";
        items[3] = "You see bushes full of berries.";
        items[4] = "oak";
        items[5] = "This oak tree is very big and old. It's so big that you could\n"+
                        "easily build a house to the oak.";

        set_sound(30+random(30),"You hear someone walking above you.\n");
}

climb(str) {
        if(str == "oak" || str == "tree") {
                write("You start to climb the oak.\n");
                say(this_player()->query_name()+" starts to climb the oak.\n");
                this_player()->move_player("up#/wizards/rag/elf/u_e4");
                return 1;
        }
        write("Climb what?\n");
        return 1;
}