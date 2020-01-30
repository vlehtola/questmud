inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 21);
    set_race("human");
    call_other(this_object(), "set_name", "Man");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "A suspicious-looking man");
    call_other(this_object(), "set_long", "A poor looking man. Beware, he could very well be a bandit.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    set_gender(1);
    
    weapon = clone_object("/wizards/nalle/jerusalem/eq/dagger");
    move_object(weapon, this_object());
    init_command("wield dagger");
}
