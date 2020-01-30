inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 29);
    call_other(this_object(), "set_name", "angel");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A loyal angel guard guarding the crow");
    call_other(this_object(), "set_long", "A loyal angel is guarding the way to the crows room. He is\n" +
                                          "looking similar like any another guard but still\n" +
                                          "there is something wrong with him.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("down");
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+110);
    move_object(money, this_object());
}



