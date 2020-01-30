inherit "obj/monster";
 
reset(arg) {
    object money;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 35);
    call_other(this_object(), "set_name", "cannibal");
    call_other(this_object(), "set_alias", "guard");
    call_other(this_object(), "set_short", "Huge cannibal guard is staring you");
    call_other(this_object(), "set_long",
    "Guard is staring you madly.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);
    set_block_dir("hut");
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    weapon = clone_object("/wizards/morgoth/cannibal/item/gsword");
    move_object(weapon, this_object());
    init_command("wield sword");
}
 
 
