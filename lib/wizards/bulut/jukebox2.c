short() { return "A jukebox is here"; }
long(str) {
write("This is a jukebox. There is a coin slot on it\n");
    return;
}

play_box() {
        if (this_player()->query_money() >= 1) {
            this_player()->reduce_money(1);
}
write("You flip a coin and put it into the jukebox.\n");

    say(capitalize(this_player()->query_name()) +
        " inserts a coin into the jukebox.\n");

say("It starts to play music!\n");
call_out("plang",4);
call_out("pling",7);
return;
}
init() {
    add_action("play_box", "insert coin");
}

id(str) { return str == "jukebox"; }

get(jukebox) {
    write("It is secured to the ground!.\n");
}

plang() {
}
pling() {
write ("Jukebox continues: Thundering hair he had, many orc's he slayed.");
write ("Jukebox ends:say(capitalize(this_player()->query_name()) +" is a jerk.\n");
}

