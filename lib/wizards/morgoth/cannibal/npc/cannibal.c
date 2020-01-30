inherit "obj/monster";
 
reset(arg) {
    object money;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 25);
    call_other(this_object(), "set_name", "cannibal");
    call_other(this_object(), "set_alias", "citizen");
    call_other(this_object(), "set_short", "A cannibal citizen");
    call_other(this_object(), "set_long",
    "This cannibal is thin and odd looking guy.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_max_hp", 26000);
    call_other(this_object(), "set_hp", 26000);
    call_other(this_object(), "set_str", 145);
    set_skill_chance("kick", 25); 
    set_skill("kick", 75);
    call_other(this_object(), "set_aggressive", 0);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/morgoth/cannibal/item/boots");
    move_object(armour, this_object());
    init_command("wear boots");
}
