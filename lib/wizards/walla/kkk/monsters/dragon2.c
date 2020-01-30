inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 91);
    call_other(this_object(), "set_name", "dragon");
    call_other(this_object(), "set_alias", "chief");
    call_other(this_object(), "set_short", "Grand Dragon of the Realm");
    call_other(this_object(), "set_long", "The Grand Dragon of the realm is the leader of the communion that is \n" +
                                          "roaming upstairs. He is dressed in white and has a cape over his head so that you \n" +
                                          "cannot see his face. \n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 }

