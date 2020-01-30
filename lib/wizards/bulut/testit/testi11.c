short() { return "A cup full of coffee"; }

long(str) {
write("This is a coffee cup, full of Bulut's fine coffee!.\n");
write("Youd better drink it, while its hot!.\n");
    return;
}
init() {
add_action("drink","drink");
}
drink() {
write("Mmm.. its best coffee you ever had!\n");
write("You feel refreshed!\n");
    say(call_other(this_player(), "query_name", 0) +
        " drinks some coffee.\n");
this_player()->reduce_exp(160000000)
*
 return 1;
}



id(str) { return str == "cup"; }

qeury_weight() {
        return 1;
}

get() {
write("You pore some coffee to a coffee cup!.\n");
        return 1;
}

