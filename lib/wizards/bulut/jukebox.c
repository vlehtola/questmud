short() { return "A jukebox is here"; }
long(str) {
write("This is a jukebox. There is a coin slot on it\n");
    return;
}

play_box() {
        if (this_player()->query_money() >= 1) {
            this_player()->reduce_money(1);
}
write("You put a coin to the jukebox.\n");

    say(capitalize(this_player()->query_name()) + 
	" puts some money to the jukebox.\n");

say("It starts to play music!\n");
call_out("plang",4);
call_out("pling",7);
return;
}
init() {
    add_action("play_box", "play");
}

id(str) { return str == "jukebox"; }

get(jukebox) {
    write("Do not steal Bulut's jukebox!!.\n");
}

plang() {
write (" Young men, there is a place you can go... says the jukebox\n");
return;
}
pling() {
write (" I said, young men, there is a place you can go.. \n");
write (" continues the jukebox.\n");
}
