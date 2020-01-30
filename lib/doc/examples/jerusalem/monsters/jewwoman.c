inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_race("human");
    call_other(this_object(), "set_level", 20);
    call_other(this_object(), "set_name", "Woman");
    call_other(this_object(), "set_alias", "woman");
    call_other(this_object(), "set_short", "A Jewish woman, looking after her children");
    call_other(this_object(), "set_long", "A woman with beautiful dark hair, is watching her children play.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    
    weapon = clone_object("/wizards/nalle/jerusalem/eq/broom");
    move_object(weapon, this_object());
    init_command("wield broom");
}

