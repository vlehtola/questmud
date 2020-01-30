inherit "room/room";

reset(arg) {
add_exit("west", "/wizards/aarrgh/nyxi/path2.c");
short_desc = "In the ruins";
long_desc = "You are standing at the nearby ruins. There are bones and dust all over the room\n"
	    "You notice a Statue of Morfeus himself in the center. The statue seems to emit some\n"
	    "strange glow. There is definetly something special about this room.\n";

items = allocate(2);
items[0] = "statue";
items[1] = "This is the statue of Morfeus holding a spectre";

}


init() {
    ::init();
add_action("push1", "push");
}

int check;

push1(str)  {

   object skeletoni;


    if(str != "statue"  ) {

	write("push what?\n");
	return 1;
	}

	skeletoni = clone_object("/wizards/aarrgh/nyxi/mon/skelppari");

    if(str == "statue" && check == 1 ) {

		write("The statue has been already pushed.\n");

	return 1;

}
    if(str == "statue" && present("skeleton", environment(this_player() ))) {

	write("The statue is pushed.\n");
	return 1;
}

    if(str == "statue" && check != 1 && !present("skeleton", environment(this_player() ))) {
write("You push the statue and it moves backwards!\n");
say(this_player()->query_name()+" pushes the statue and it moves backwards.\n");
add_exit("east", "/wizards/aarrgh/nyxi/ruin2.c");
this_player()->set_quest("push_statue", 2);
//	move_object(skeletoni, environment(this_player() ));
    tell_room("/wizards/aarrgh/nyxi/mist.c",
	"The demonic skeleton is awakened!\n");

    check = 1;

    return 1;


}

}




