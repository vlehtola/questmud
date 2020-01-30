inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 5);
    call_other(this_object(), "set_name", "snail");
    call_other(this_object(), "set_alias", "blob");
    call_other(this_object(), "set_short", "A happy little yellow snail squirms around");
    call_other(this_object(), "set_long", "The snail is looks about normal, except for its\n" +
                                          "large size and strange color. It seems as though it is not\n" +
                                          "completely normal.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

     money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

}

