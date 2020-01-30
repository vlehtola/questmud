short() { return "A heavy cross"; }
id(str) { return str == "cross"; }

init() {
    add_action("eika", "drop");
    add_action("eika", "give");
    add_action("eika", "toss");
    add_action("juokse", "north");
    add_action("juokse", "south");
    add_action("juokse", "east");
    add_action("juokse", "west");
    add_action("ld", "ld");
    add_action("quit", "quit");
}

long(str) {
write("A heavy wooden cross.\n");
    return;
}

ld() {
write("No. You cannot do that.\n");
return 1;
}

juokse(arg) {
write("You cannot move because of the weight of the cross.\n");
return 1;
}

quit(arg) {
destruct(this_object());
return;
}

eika(arg) {
write("You simply cannot do it!\n");
return 1;
}

get() {
    return 1;
}
