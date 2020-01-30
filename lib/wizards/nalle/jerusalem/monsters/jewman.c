inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 21);
    call_other(this_object(), "set_name", "Man");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "A Jewish man, looking for useful things to buy");
    call_other(this_object(), "set_long", "A man with neat dark clothes and a perceptive look in his eyes.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    
    weapon = clone_object("/wizards/nalle/jerusalem/eq/knife");
    move_object(weapon, this_object());
    init_command("wield dagger");
}

