inherit "room/room";
int i;

reset(arg) {

        if(!present("bear")) {
                move_object(clone_object("/wizards/jenny/mehta/mosut/bear.c"), this_object());
        }

        if(arg) return;
        i = 0;

        add_exit("southeast","/wizards/jenny/mehta/huoneet/forest3.c");
 
        short_desc = "In a peaceful forest";
        long_desc = "You have arrived to a dead end, there is a gigantic cliff\n"+ 
                        "blocking your way. Some odd looking plants are growing nearby\n"+
                        "and there is a small crack on the cliff. Some footprints seem\n"+
                        "to be on the ground. It is getting pretty cold in here.\n";

        items = allocate(8);
        items[0] = "cliff";
        items[1] = "A normal looking cliff which seems to be very steep.";
        items[2] = "plants";
        items[3] = "Delicate looking plants are growing on the cliff.";
        items[4] = "crack";
        items[5] = "A small crack formed by nature, there might be something in it.";
        items[6] = "footprints";
        items[7] = "A huge grizzly has been wandering around here.";
}

search_finished(str) {
        if(!i && str == "crack") {
                object bone;
                write("You stick your hand in the crack and find something awful.\n");
                say(this_player()->query_name()+ " found something from the crack.\n"); 
                bone = clone_object("/wizards/jenny/mehta/rojut/bone.c");
                move_object(bone, this_player());
                i = 1; 
                return 1;
        }
        if(i && str == "crack") {
                write("You stick your hand in the crack, but can't find anything.\n");
                say(this_player()->query_name()+ " shrugs idly.\n");
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " found nothing.\n");
        return 1;
}
