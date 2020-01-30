inherit "obj/monster";
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 13);
    call_other(this_object(), "set_name", "pawn");
    call_other(this_object(), "set_alias", "pawn");
    call_other(this_object(), "set_short", "A black pawn of the chessboard");
    call_other(this_object(), "set_long", "This pawn stands straight up and doesn't seem to move.\n" +
                                          "He stands in the front row.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10000)+1000);
    move_object(money, this_object());
 
}
