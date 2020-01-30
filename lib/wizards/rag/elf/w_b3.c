inherit "room/room";
int i;

reset(arg) {
        if(arg) return;
        i = 0;

        add_exit("west","/wizards/rag/elf/w_b2");

        short_desc = "At a dead end";
        long_desc = "The tunnel has caved in here. There is no way to\n"+
                        "continue. The ceiling has collapsed totally. A big\n"+
                        "pile of rocks is the only thing left from the accident.\n"+
                        "A small layer of dust has descended on the floor.\n";

        items = allocate(2);
        items[0] = "rocks";
        items[1] = "There might be something buried under the rocks";
}

search_finished(str) {
        if(!i && str == "rocks") {
                write("You move some rocks and find a key!\n");
                say(this_player()->query_name()+ " founds something.\n");
                move_object("/wizards/rag/elf/objects/key",this_player());
                i = 1;
                return 1;
        }
        if(i && str == "rocks") {
                write("It seems that someone has already searched here.\n");
                say(this_player()->query_name()+ " looks disappointed.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
