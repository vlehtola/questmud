inherit "obj/monster";
 
reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "knight");
    call_other(this_object(), "set_alias", "knight");
    call_other(this_object(), "set_short", "A white knight of the chessboard");
    call_other(this_object(), "set_long", "This knight hops around the chessboard\n" +
                                          "making great leaps.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10000)+1000);
    move_object(money, this_object());
 
}
