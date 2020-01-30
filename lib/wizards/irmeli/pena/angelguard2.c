inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 34);
    call_other(this_object(), "set_exp", 1264967);
    call_other(this_object(), "set_name", "angel");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "A loyal angel guard guarding the emperor");
    call_other(this_object(), "set_long", "A loyal angel is guarding the way to the emperors room.\n" +
                                          "He is bigger than any another guard in here.\n" +
                                          "His hands is all over covered with blood.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("north");
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(20)+110);
    move_object(money, this_object());
}



