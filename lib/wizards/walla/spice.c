inherit "obj/monster"; 
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 121);
    call_other(this_object(), "set_name", "claudia");
    call_other(this_object(), "set_alias", "claudia");
    call_other(this_object(), "set_short", "Claudia Schiffer makes magic for Walla");
    call_other(this_object(), "set_long", "Claudia is (one of) Wallas hani(s).\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("east");
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
}
