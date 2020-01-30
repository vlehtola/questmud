get_time() {
    return 3;
}
ep_cost() { return 5; }
query_type() { return "neutral"; }

resolve_skill(str) {
        object ob;
        ob = present("tamer_obj", this_player());
        if(!ob) { write("You don't have an animal.\n"); return 1; }
        write("You make noises and call your animal back.\n");
        say(this_player()->query_name()+" calls "+this_player()->possessive()+" animal back.\n");
        ob->move_test();
    return 1;
}

fail_skill(str) {
        write("You fail to call your animal back.\n");
    return 1;
}
