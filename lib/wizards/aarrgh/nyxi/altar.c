inherit "room/room";
object monster;
reset(arg) {

set_light(1);
set_not_out(1);
            add_exit("out", "/wizards/aarrgh/nyxi/cave.c");
            short_desc = "Altar room";
long_desc = "This room is a large altar room. It flows with magical energy and gains its powers from\n"
            "the pool morfeus has been using for sacrifices. Altar in the center looks interesting\n";
items = allocate(4);
items[0] = "altar";
items[1] = "This altar is used for praying for the powers of Nyx";

}


init() {
    ::init();
add_action("pray1", "pray");
}

int check;

pray1(str)  {

   object nyxi;


    if(str != "altar"  ) {

	write("Pray what?\n");
	return 1;
	}

	nyxi = clone_object("/wizards/aarrgh/nyxi/mon/nyx");

    if(str == "altar" && check == 1 ) {

		write("You can only pray once.\n");

	return 1;

}
    if(str == "altar" && present("nyxi", environment(this_player() ))) {

	write("The Nyx is present.\n");
	return 1;
}

    if(str == "altar" && check != 1 && !present("nyx", environment(this_player() ))) {
write("You have summoned the mighty and powerful Nyx!\n");
say(this_player()->query_name()+" prays the altar and suddenly The Nyx has been summoned!\n");
	move_object(nyxi, environment(this_player() ));
    tell_room("/wizards/aarrgh/nyxi/cave.c",
	"The Nyx has been summoned!\n");

    check = 1;

    return 1;


}
}
