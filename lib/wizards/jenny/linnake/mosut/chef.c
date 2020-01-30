inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 35);
    call_other(this_object(), "set_name", "chef");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "Chef is cooking dinner for the castle");
    call_other(this_object(), "set_long", "Muscular looking tall chef is cooking dinner for the castle\n"+
                                          "here. He is wielding small but sharp looking kitchen knife\n"+
                                          "and he looks very busy. You should not distract him when he\n"+
                                          "is cooking.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
 
    weapon = clone_object("/wizards/jenny/linnake/rojut/chef_knife.c");
    move_object(weapon, this_object());
    init_command("wield knife");
}
