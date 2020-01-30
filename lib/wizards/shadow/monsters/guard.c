inherit "obj/monster";

reset(arg) {
    object money;
    ::reset(arg);
    call_other(this_object(), "set_level", 1);
    call_other(this_object(), "set_hp", 5);
    call_other(this_object(), "set_name", "ant");
    call_other(this_object(), "set_alias", "worker");
    call_other(this_object(), "set_short", "An ant worker");
    call_other(this_object(), "set_long", "What you see before you is not " +
                "an ordinary few inches long ant, but a human\n" + 
                "sized, quite intelligent looking being, which is carrying food\n" +
                "on its back to the ant society, its nest.\n");
    call_other(this_object(), "set_wc", 3);
    call_other(this_object(), "set_ac", 0);
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
}
