short() { return "A bunch of green herbs"; }
id(str) { return str == "herbs"; }

long(str) {
write("A bunch of funny-smelling green herbs tied together.\n");
    return;
}

init() {
    add_action("eat", "eat");
}

eat() {
    object ob;
    write("You happily chew on the sticky herbs.\n");
    say(call_other(this_player(), "query_name", 0) +" chews on the herbs.\n");
    ob = present("poisonob", this_player());
    if (ob) {destruct(ob); write("You feel much better already.\n");}
    this_player()->remove_poison();
    destruct(this_object());
    return 1;
}

get() {
    return 1;
}

