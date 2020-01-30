inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 10);
    call_other(this_object(), "set_name", "bob");
    call_other(this_object(), "set_alias", "sir");
    call_other(this_object(), "set_short", "Sir Bob in his tall hat and elegant dress");
    call_other(this_object(), "set_long", "Sir Bob seems to enjoy the great spring weather\n" +
                                          "at least for as long as it lasts. He looks like a perfectly\n" +
                                          "normal chap.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

     money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

}
