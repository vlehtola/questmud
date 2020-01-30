inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_animal(1);
    call_other(this_object(), "set_level", 30);
    call_other(this_object(), "set_name", "small skeleton");
    call_other(this_object(), "set_alias", "skeleton");
    call_other(this_object(), "set_short", "A small skeleton");
    call_other(this_object(), "set_long", "Oi ihana lurkku on on.\n");
    call_other(this_object(), "set_aggressive", 1);
    set_exp(query_exp() / 6);
        set_animal(1);
}

catch_tell(str) {
    string tmp1,tmp2;
    object ob;
    if (sscanf(str, "%s leaves %s", tmp1, tmp2) == 2) {
        ob = find_player(lower_case(tmp1));
        if (!ob) { return; }
        call_out("seko",1,ob);
    }
}
seko(ob) {
        move_player("after " + ob->query_name(), environment(ob));
        attack_object(ob);
}

monster_died() {
    object ob;
    ob = find_object("/wizards/yodin/lord");
    if (!ob) { return; }
    ob->reduce_number();
}
