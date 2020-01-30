inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_animal(1);
    call_other(this_object(), "set_level", 10);
    call_other(this_object(), "set_name", "small ant");
    call_other(this_object(), "set_alias", "ant");
    call_other(this_object(), "set_short", "A small ant");
    call_other(this_object(), "set_long", "This is a small ant just born from an egg. Still it seem very\n" +
                                        "aggressive. It has small claws, which already have some strenght in\n" +
                                        "them.\n");
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
    ob = find_object("/world/monsters/antqueen");
    if (!ob) { return; }
    ob->reduce_number();
}
