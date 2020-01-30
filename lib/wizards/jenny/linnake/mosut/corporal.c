inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 32);
    call_other(this_object(), "set_name", "corporal");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "Corporal looking important");
    call_other(this_object(), "set_long", "Well dressed corporal with standard guard equipment.\n"+
                                          "He has brown eyes and long black hair, he also looks\n"+
                                          "kind, but somehow you get the feeling that everything\n"+
                                          "is not right.\n");
    call_other(this_object(), "set_al", 0); 
    call_other(this_object(), "set_aggressive", 0);
     
    armour = clone_object("/wizards/jenny/linnake/rojut/black_armour.c");
    move_object(armour, this_object());
    init_command("wear armour");
 
    weapon = clone_object("/wizards/jenny/linnake/rojut/guard_sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
