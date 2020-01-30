inherit "room/room";
int soul;

reset(arg) {
	if(arg) return;

	soul = 0;

        add_exit("north","/wizards/rag/ruins/burn7");
        
        short_desc = "At the end of the bridge";
        long_desc =     "Intensive heat flows from the burning lake beneath your feet. Massive\n"+
                        "bridges arch over burning lava. There are several levels of bridges\n"+
                        "and on each level you can see many soldiers training under the burning\n"+
                        "whips of guarding demons. Some soldiers fall to the lake but they are\n"+
                        "instantly replaced with new trainees. A huge flaming pillar stands in\n"+
			"the middle of this platform.\n";

        items = allocate(2);
        items[0] = "pillar";
        items[1] = "There seems to be something burning within the pillar";

        set_not_out(1);
}

chant(str) {
        if(str == "glacies" && !soul) {
        tell_room(this_object(),"The scroll cools down the heat so much that the pillar dies for just a second.\n");
	write("You reach out your hand and grab the thing that was burning inside the pillar.\n");
	say(this_player()->query_name()+" reaches out and grabs the thing that was burning inside the pillar.\n");
	move_object(clone_object("/wizards/rag/ruins/obj/soul"),this_player());
	soul = 1;
	call_out("burn",2);
        return 1;
        }
	if(str == "glacies" && soul) {
	tell_room(this_object(),"The scroll cools down the heat so much that the pillar dies for just a second.\n");
	call_out("burn",2);
	return 1;
	}
}

burn() {
	tell_room(this_object(),"The pillar bursts back to flames.\n");
	return 1;
}
