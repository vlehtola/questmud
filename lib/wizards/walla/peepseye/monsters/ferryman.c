inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 2);
    call_other(this_object(), "set_name", "rat");
    call_other(this_object(), "set_alias", "animal");
    call_other(this_object(), "set_short", "A small rat");
    call_other(this_object(), "set_long", "The rat looks at you with its red glowing eyes and seems to be very\n" +
                                          "hungry. You appear to be the target.\n");
    call_other(this_object(), "set_al", -6);
    call_other(this_object(), "set_aggressive", 0);

     money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

}
 
