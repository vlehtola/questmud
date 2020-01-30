inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 43);
    call_other(this_object(), "set_name", "queen");
    call_other(this_object(), "set_alias", "queen");
    call_other(this_object(), "set_short", "The white queen");
    call_other(this_object(), "set_long", "The queen is the most utile of all pieces.\n" +
                                          "It can walk in any direction.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(10000)+1000);
    move_object(money, this_object());

armour = clone_object("/wizards/walla/chessboard/armour/wshoes");
    move_object(armour, this_object());
    init_command("wear shoes");


}
