inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 1);
    call_other(this_object(), "set_name", "ant");
    call_other(this_object(), "set_alias", "worker");
    call_other(this_object(), "set_short", "A giant ant worker");
    call_other(this_object(), "set_long", "The is huge compared to its smaller relatives. It is atleast\n" +
                                          "one and a half meters long and one meter high.It is digging the\n" +
                                          "wall and your presence doesn't seem to distracting it in its work.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());

    armour = clone_object("/world/mine/eq/shell");
    move_object(armour, this_object());
    init_command("wear shell");

    weapon = clone_object("/world/eq/weapons/mace");
    move_object(weapon, this_object());
    init_command("wield mace");
}
