cmd_heal(name) {
    object ob;
    int Wiza;
    Wiza = this_player()->query_wiz();
    if (!name)
        return 0;
    ob = find_living(name);
    if (!ob) {
        write("No such person is playing now.\n");
        return 1;
    }
    if(Wiza < 2 && !ob->query_npc() && ob != this_player()) return;
    call_other(ob, "heal_self", 100000);
    tell_object(ob, "You are healed by " + this_player()->query_name() + ".\n");
    write("You healed " + capitalize(name) + ".\n");
    return 1;
}

