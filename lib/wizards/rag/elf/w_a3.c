inherit "room/room";
int i;

reset(arg) {

        if(!present("troll")) {
                move_object(clone_object("/wizards/rag/elf/monsters/troll"), this_object());
        }

        if(arg) return;
        i = 0;

        add_exit("southwest","/wizards/rag/elf/w_b4");

        short_desc = "In a dead end";
        long_desc = "Tunnel leads back to northeast. Grunts and shouts can be heard\n"+
                        "from a distance. The walls seem to be carved very roughly but\n"+
                        "efficiently. The air is damp and smells like death. There are\n"+
                        "some crates in the corner.\n";

        items = allocate(2);
        items[0] = "crates";
        items[1] = "The crates are full of supplies, but you get the feeling that you\n"+
                        "should search more thoroughly";

        set_not_out();
}

search_finished(str) {
        if(!i && str == "crates") {
                write("You move some crates and find some coins.\n");
                say(this_player()->query_name()+ " founds something.\n");
                this_player()->add_money((random(30)+10)*(random(3)+2),3);
                i = 1;
                return 1;
        }
        if(i && str == "crates") {
                write("It seems that someone has already searched here.\n");
                say(this_player()->query_name()+ " looks disappointed.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
