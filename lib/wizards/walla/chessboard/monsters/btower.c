inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 17);
    call_other(this_object(), "set_name", "rook");
    call_other(this_object(), "set_alias", "rook");
    call_other(this_object(), "set_short", "A black rook of the chessboard");
    call_other(this_object(), "set_long", "This rook has for mission to guard the corner\n" +
                                          "of the chessboard.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10000)+1000);
    move_object(money, this_object());

}

