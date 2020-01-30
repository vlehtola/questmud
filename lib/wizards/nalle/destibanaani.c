short() { return "A banana"; }
id(str) { return str == "banana"; }

long(str) {
write("A little banana waiting to get peeled.\n");
    return;
}

init() {
    add_action("peel", "peel");
}

peel() {
    write("The banana squeaks loudly as you peel it softly. It then goes off.\n");
    say(call_other(this_player(), "query_name", 0) +" peels his banana fondly, which goes off.\n");
    destruct(present(this_object()));
}

get() {
    return 1;
}

