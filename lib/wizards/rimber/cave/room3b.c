inherit "room/room";
int i;

reset(arg) {
	if(arg) return;
        i = 0;
	set_light(3);
	short_desc = "Dark and damp cavern";
 long_desc = "The cave here is very spacious. Really small tunnels go\n"+
             "every direction. Dark dweller warriors come to drink water\n"+
 "in here. A small stream flows across the cave.\n"+
             "There seems to be some footprints near the stream.\n";
	items = allocate(4);
	items[0] = "stream";
        items[1] = "A small stream flows from inside the wall and continues across the cave.";
        items[2] = "footprints";
 items[3] = "It seems that the footprints on the ground start from the stream,\n"+
  "circle around the room and then lead back to the small stream.";
        add_exit("south", "/wizards/rimber/cave/room3.c");
 set_not_out(1);
}

search_finished(str) {
	if(i == 0 && str == "stream") {
		object jewel;
                jewel = clone_object("/wizards/rimber/cave/obj/earring.c");
                say(this_player()->query_name()+" carefully examines the stream and then picks something up from there.\n");
                write("You look into the stream carefully and see something glittering. It's an earring.\n");
                move_object(jewel, this_player());
		i = 1;
		return 1;
	}
	if(i == 1 && str == "stream") {
                say(this_player()->query_name()+" searches the stream but founds nothing.\n");
		write("You search sometime but find nothing.\n");
		return 1;
	}
	write("You find nothing special.\n");
	return 1;
}
