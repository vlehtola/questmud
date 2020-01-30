inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_race("human");
    call_other(this_object(), "set_level", 20);
    call_other(this_object(), "set_name", "woman");
    call_other(this_object(), "set_alias", "Woman");
    call_other(this_object(), "set_short", "A Christian woman, walking with her children");
    call_other(this_object(), "set_long", "A woman taking her children to cathedral school.\n");
    call_other(this_object(), "set_al", 5);
    call_other(this_object(), "set_aggressive", 0);
    
    weapon = clone_object("/wizards/nalle/jerusalem/eq/broom");
    move_object(weapon, this_object());
    init_command("wield dagger");
}
