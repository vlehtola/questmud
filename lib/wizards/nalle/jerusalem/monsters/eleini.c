inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 40);
    call_other(this_object(), "set_name", "shopkeeper");
    call_other(this_object(), "set_alias", "el-eini");
    call_other(this_object(), "set_short", "Shopkeeper El-Eini, is standing behind the counter");
    call_other(this_object(), "set_long", "A darkhaired man who seems to take good care of his money.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
    
    weapon = clone_object("/wizards/nalle/jerusalem/eq/sword");
    move_object(weapon, this_object());
    init_command("wield sword");
}

