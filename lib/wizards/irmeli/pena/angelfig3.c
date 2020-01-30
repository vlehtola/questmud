inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 17);
    call_other(this_object(), "set_name", "huge angel");
    call_other(this_object(), "set_alias", "angel");
    call_other(this_object(), "set_short", "A huge angel is digging grave to you");
    call_other(this_object(), "set_long", "A huge angel is digging grave to you. He is bigger than the earlier\n" +
                                          "ones and he is more muscular than the anothers. He is big\n" +
                                          "enought to crush you.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir();
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+20);
    move_object(money, this_object());
}



