inherit "room/room";
int i;

reset(arg) {

        if(!present("ghost")) {
                move_object(clone_object("/wizards/rag/elf/monsters/ghost"), this_object());
        }

        if(arg) return;
        i = 0;

        add_exit("up","/wizards/rag/elf/e_e6");

        short_desc = "Bottom of the pond";
        long_desc = "You are in the bottom of the pond. You can't breath\n"+
                        "and you think you're drowning. The water is surprisingly\n"+
                        "deep. There are dead bodies at the bottom of the pond.\n"+
                        "You fear that you will soon join them.\n";

        set_water(10);
        items = allocate(2);
        items[0] = "bodies";
        items[1] = "Rotting bodies lie at the bottom, their treasures still intact";
}

search_finished(str) {
        if(!i && str == "bodies") {
                write("You search the bodies and find some coins.\n");
                say(this_player()->query_name()+ " founds something.\n");
                this_player()->add_money((random(20)+25)*(random(3)+2),3);
                i = 1;
                return 1;
        }
        if(i && str == "bodies") {
                write("It seems that someone has already looted the bodies.\n");
                say(this_player()->query_name()+ " looks disappointed.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
