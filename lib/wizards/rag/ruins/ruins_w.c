inherit "room/room";
int i;

reset(arg) {
        if(arg) return;
        add_exit("south","/wizards/rag/ruins/ruins_sw");
        i = 0;

        short_desc = "At the cemetery";
        long_desc =     "A raging storm makes it hard to see anyting. The pouring\n"+
                        "rain has made the ground muddy and slippery. There are\n"+
                        "looted graves everywhere. An army of grave robbers seems\n"+
                        "to have rampaged this cemetery. Only one tombstone stands\n"+
                        "in the middle of the cemetery.\n";

        items = allocate(8);
        items[0] = "church";
        items[1] = "The church is burned and it's walls have collapsed";
        items[2] = "tombstone";
        items[3] = "The tombstone stands next to an untouched grave.\n"+
                "There is something written on the tombstone:\n"+
                "Here lies the Champion of Light";
        items[4] = "grave";
        items[5] = "The grave is the only one left untouched. Perhaps\n"+
                "there is still something left in the grave";

        set_sound(19+random(6),"Rain pours heavily down from the sky.\n");
        set_sound(28+random(6),"Thunder and lightning rage over the church.\n");
}

search_finished(str) {
        if(str == "grave" || str == "graves") {
                if(!i) {
                write("You search the grave and find a rusty sword.\n");
                move_object(clone_object("/wizards/rag/ruins/obj/sword"),this_player());
                this_player()->fix_weight();
                say(this_player()->query_name()+" searches the grave and finds a rusty sword.\n");
                i = 1;
                return 1;
                } else {
                write("It seems that somebody has already searched here.\n");
                say(this_player()->query_name()+" looks a bit disappointed.\n");
                return 1;
                }
        }
        else { 
                write("Search what?\n");
                return 1;
        }
}               
