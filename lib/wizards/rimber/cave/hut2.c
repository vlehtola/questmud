inherit "room/room";

reset(arg) {
	if(arg) return;
	set_light(3);
        add_exit("out", "/wizards/rimber/cave/room13.c");
	short_desc = "In the dweller hut";
 long_desc = "Everything seems to be neatly in its place in this hut.\n"+
  "Claypots have their own place in the corner and they seem\n"+
  "to be arranged in precise order. Spears lean against the wall\n"+
  "near the bed. Everything looks ordinary except for the bookshelf\n"+
  "which is empty and dusty. A pile of ox hides lays on the ground.\n";
        items = allocate(10);
	items[0] = "claypots";
        items[1] = "One huge pot stands in the corner, separated from the rest of the claypots.";
	items[2] = "bookshelf";
        items[3] = "The shelf is really dirty. There is something wrong with this shelf.";
	items[4] = "bed";
	items[5] = "No-one has slept here for a while.";
	items[6] = "pot";
        items[7] = "The pot is so big that you could climb into it.";
        items[8] = "pile";
        items[9] = "A large pile of ox hides.";
}

init() {
	::init();
	add_action("climb", "climb");
       add_action("push", "push");
}

climb(str) {
	if(str == "pot") {
        write("You climb into the pot and fall down to another room.\n");
        say(this_player()->query_name()+" climbs into the pot and falls in it.\n");
	move_object(this_player(), "/wizards/rimber/cave/room41.c");
	return 1;
	}
 return 0;
}
push(str) {
	if(str == "shelf" || str == "bookshelf") {
		object paper;
                paper = clone_object("/wizards/rimber/cave/obj/paper.c");
                say(this_player()->query_name()+" turns to red when pushing the shelf half a meter.\n");
		write("You push and push and finally the shelf moves. Behind the shelf is nothing but a piece of paper.\n");
		move_object(paper, this_player());
		return 1;
	}
return 0;
}
search_finished(str) {
	if(str == "shelf" || str == "bookshelf") {
		say(this_player()->query_name()+" dusts the shelf and founds something.\n");
		write("You find a text: 'Hide and seek I play, it's my favorite game,\n"+
			"I hide from you, it's fun but cruel, find me am I in this room?\n"+
                        "You notice that the shelf has been moved recently.\n");
		return 1;
	}
	if(str == "pile") {
		object puupala;
                puupala = clone_object("/wizards/rimber/cave/obj/pala.c");
		say(this_player()->query_name()+" searches the pile of hides and finds something.\n");
		write("You move heavy hides out of your way but all you find is a piece of wood.\n");
		move_object(puupala, this_player());
		return 1;
	}
	write("You find nothing special.\n");
	return 1;
}
