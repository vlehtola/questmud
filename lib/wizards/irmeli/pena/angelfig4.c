inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 22);
    call_other(this_object(), "set_name", "massive angel");
    call_other(this_object(), "set_alias", "angel");
    call_other(this_object(), "set_short", "A massive angel waiting for victim");
    call_other(this_object(), "set_long", "A massive angel is waiting to victim to kill. This angel seems like\n" +
                                          "he has been waiting here for years. Long and dirty beard is\n" +
                                          "touching his feets.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 1);
    set_block_dir();
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+25);
    move_object(money, this_object());
}



