inherit "room/room";

reset(arg) {
set_light(1);
set_not_out(1);
            add_exit("out", "/wizards/aarrgh/nyxi/mist.c");
            short_desc = "Inside a dusty tomb";
long_desc = "This is a dark tomb with few gothic style windows on each wall. This room is\n"
            "much darker than outside. A dusty tombstone lies in thecenter of this ancient\n"
            "tomb and it seems to be ancient and covered with dust.\n";
items = allocate(4);
items[0] = "tombstone";
items[1] = "This tombstone is covered with ancient runes. The tombstone seems to hold something inside";

}

init() {
    ::init();
add_action("open1", "open");
}

int check;

open1(str)  {

   object skeletoni;


    if(str != "tombstone"  ) {

	write("open what?\n");
	return 1;
	}

	skeletoni = clone_object("/wizards/aarrgh/nyxi/mon/skelppari");

    if(str == "tombstone" && check == 1 ) {

		write("The tombstone is already empty.\n");

	return 1;

}
    if(str == "tombstone" && present("skeleton", environment(this_player() ))) {

	write("The monster is present.\n");
	return 1;
}

    if(str == "tombstone" && check != 1 && !present("skeleton", environment(this_player() ))) {
write("You have waken the demonic skeleton!\n");
say(this_player()->query_name()+" opens the tomb and the skeleton raises on its feet.\n");
this_player()->set_quest("Wake the mystical skeleton", 2);//    call_other("/wizards/aarrgh/nyxi/mist.c",
	move_object(skeletoni, environment(this_player() ));
    tell_room("/wizards/aarrgh/nyxi/mist.c",
	"The demonic skeleton is awakened!\n");

    check = 1;

    return 1;


}
}
