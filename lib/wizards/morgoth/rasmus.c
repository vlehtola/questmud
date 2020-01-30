inherit "obj/monster";
 
reset(arg) {
    object money;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 75);
    call_other(this_object(), "set_name", "Rasmus");
    call_other(this_object(), "set_alias", "nalle");
    call_other(this_object(), "set_short", "Rasmus Nalle.");
    call_other(this_object(), "set_long",
    "This is cannibal king.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    weapon = clone_object("/wizards/morgoth/cannibal/item/wepa");
    move_object(weapon, this_object());
    init_command("wield sword");
 
}
