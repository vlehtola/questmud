inherit "room/room";
string str;
object monster;
int i;

reset(arg) {
        i = random(15);
        str = "";

        switch(i) {
        case 0..2: str = "/wizards/rag/elf/monsters/hare"; break;
        case 3..5: str = "/wizards/rag/elf/monsters/snake"; break;
        case 6..7: str = "/wizards/rag/elf/monsters/fox"; break;
        case 8..9: str = "/wizards/rag/elf/monsters/deer"; break;
        case 10: str = "/wizards/rag/elf/monsters/wolf"; break;
        case 11..13: str = "/wizards/rag/elf/monsters/bear";
        case 14: str = ""; break;
        }

        if(!monster && str != "") {
         monster = clone_object(str);
         move_object(monster, this_object());
        }
        if(arg) return;

        add_exit("west","/wizards/rag/elf/w_f6");
        add_exit("southeast","/wizards/rag/elf/w_g2");

        short_desc = "Green plains";
        long_desc = "The path continues further to west. The forest has\n"+
                        "ended and you are standing on an open plain. Grass and\n"+
                        "flowers grow here. Hills seem to be rising to the west.\n";
        items = allocate(2);
        items[0] = "hills";
        items[1] = "The hills are not very big but they could still hide\n"+
                   "horrible secrets and treasures. You think you saw\n"+
                   "something moving in the distance near the hills";
}
