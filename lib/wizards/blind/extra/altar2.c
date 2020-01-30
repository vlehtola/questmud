inherit "room/room";

reset(arg) {
set_light(1);
set_not_out(1);
            add_exit("out", "/wizards/aarrgh/nyxi/cave.c");
            short_desc = "Altar room";
long_desc = "This room is the large altar room of prayers. It flows with magical energy and gains\n"
            "its powers the pool Morfeus has been using for sacrifices. Altar in the center \n"
            "is sculpted from white and grey bones. The presence of great power can be definetly\n"
            "noticed. A mist covers the floor and it swirls when you walk in the room. The altar\n"
            "looks interesting.\n";
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
   object hiileri;


    if(str != "altar"  ) {

	write("Pray what?\n");
	return 1;
	}

	nyxi = clone_object("/wizards/aarrgh/nyxi/mon/nyx");
    hiileri = clone_object("/wizards/aarrgh/nyxi/mon/entity");

    if(str == "altar" && check == 1 ) {

		write("You can only pray once.\n");

	return 1;

}
    if(str == "altar" && present("nyxi", environment(this_player() ))) {

	write("The Nyx is present.\n");
	return 1;
}

    if(str == "altar" && check != 1 && !present("nyx", environment(this_player() ))) {
write("You have summoned the mighty and powerful Nyx!\n\n");
write("Nyx concentrates and suddenly some strange demonic creature raises from the ground!\n");
say(this_player()->query_name()+" prays the altar and suddenly the Nyx has been summoned!\n\n");
say("Nyx chants some runes and suddenly a demonic entity raises from the ground!\n\n");
say("A demonic roars: You shall die, pathetic mortals!\n");
	move_object(nyxi, environment(this_player() ));
    move_object(hiileri, environment(this_player() ));
    tell_room("/wizards/aarrgh/nyxi/cave.c",
	"The Nyx has been summoned!\n");

    check = 1;

    return 1;


}
}