inherit "room/room";
int i;

reset(arg) {
        if(arg) return;
        add_exit("out","/wizards/rag/ruins/ruins_e");
        i = 0;

        short_desc = "In the shack";
        long_desc =     "Dusty shelves and piles of different tools are\n"+
                        "scattered around the shack. There are some boards\n"+
                        "and wood logs in the corner. The church can be\n"+
                        "seen from a broken window. The shack could crash\n"+
                        "down any minute now.\n";

        set_not_out(1);
        items = allocate(8);
        items[0] = "shelves";
        items[1] = "There are some miscellenous equipment placed on the\n"+
                "shelves. Maybe you should look more closely..";
        items[2] = "shelf";
        items[3] = items[1];
        items[4] = "piles";
        items[5] = "The piles are made of broken and dusty tools";
        items[6] = "tools";
        items[7] = items[5];

        
        move_object(clone_object("/wizards/rag/ruins/obj/ladders"),this_object());

        set_sound(16+random(6),"You hear raindrops hitting the roof.\n");
        set_sound(22+random(6),"You hear thunder striking.\n");
}

search_finished(str) {
        if(str == "shelves" || str == "shelf") {
                if(!i) {
                write("You search the shelves and find a bucket.\n");
                move_object(clone_object("/wizards/rag/ruins/obj/bucket_e"),this_player());
		this_player()->fix_weight();
                say(this_player()->query_name()+" searches the shelves and finds a bucket.\n");
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
