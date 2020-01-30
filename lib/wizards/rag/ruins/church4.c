inherit "room/room";
int i;

init() {
        add_action("read","read");
        ::init();
}

reset(arg) {
        if(arg) return;
        add_exit("south","/wizards/rag/ruins/church3");
        i = 0;

        short_desc = "At the altar";
        long_desc =     "You are standing at the church altar. The symbol of Cyral has been\n"+
                        "torn down from the northern wall. The altarpiece has been burned.\n"+
                        "Shattered bottles of communion wine can be seen at the altar. There\n"+
                        "seems to be a pedestal standing among the rubble. You can see only\n"+
                        "one skeleton here.\n";

        set_not_out(1);
        items = allocate(6);
        items[0] = "pedestal";
        items[1] = "There is a book on the pedestal";
        items[2] = "book";
        items[3] = "It looks like the Holy book of Cyral but there seems to be more pages";
        items[4] = "skeleton";
        items[5] = "It is a lonely skeleton, perhaps it was the priest";

        set_sound(23+random(6),"You hear the pouring rain and the raging thunder.\n");
}

read(str) {
	if(!str) { return; }
        if(str == "book" && !present("priest") && !i) {
                write("You start to read the Holy book.\n");
                say(this_player()->query_name()+" starts to read the Holy book.\n");
                tell_room(this_object(),"You see a silvery shade over the skeleton and suddenly\n"+
                                        "the shade stands up. The priest has arrived.\n");
                move_object(clone_object("/wizards/rag/ruins/mon/priest"),this_object());
                i = 1;
                return 1;
        } else if(str == "book" && present("priest")) {
                write("The priest says: 'But I am already here, my child.'\n");
                return 1;
        } else if(str == "book" && i) {
                write("You start to read the Holy book but nothing happens.\n");
                say(this_player()->query_name()+" starts to read the Holy book but nothing happens.\n");
                return 1;
        }       
}