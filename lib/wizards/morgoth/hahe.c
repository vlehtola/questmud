inherit "obj/monster";
 
reset(arg) {
    object money;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 40);
    call_other(this_object(), "set_name", "testi");
    call_other(this_object(), "set_alias", "testi");
    call_other(this_object(), "set_short", "Testi.");
    call_other(this_object(), "set_hp", 1);
    call_other(this_object(), "set_str", 1);
    call_other(this_object(), "set_dex", 1);
    call_other(this_object(), "set_con", 1);
    call_other(this_object(), "set_int", 1);
    call_other(this_object(), "set_wis", 1);
    call_other(this_object(), "set_long",
    "This is testi.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
}
