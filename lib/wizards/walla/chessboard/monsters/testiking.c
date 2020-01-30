inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 35);
    call_other(this_object(), "set_name", "king");
    call_other(this_object(), "set_alias", "king");
    call_other(this_object(), "set_short", "The white king");
    call_other(this_object(), "set_long", "This king is the most important piece of the white\n" +
                                          "side. It is very big.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10000)+1000);
    move_object(money, this_object());

armour = clone_object("/wizards/walla/chessboard/armour/wcrown");
    move_object(armour, this_object());
    init_command("wear crown");


}
