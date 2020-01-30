inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
   set_gender(1);
    call_other(this_object(), "set_level", 24);
    call_other(this_object(), "set_name", "guard");
    call_other(this_object(), "set_alias", "human");
    call_other(this_object(), "set_short", "Hallguard watching every step you take");
    call_other(this_object(), "set_long", "Kind looking hallguard is here watching people to behave properly.\n"+
                                          "He looks quite strong and is wielding a black sword that looks\n"+
                                          "quite scary. He is wearing normal clothes but he does have an\n"+
                                          "armour on his torso.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
     
    armour = clone_object("/wizards/jenny/linnake/rojut/black_armour.c");
    move_object(armour, this_object());
    init_command("wear armour");
 
    weapon = clone_object("/wizards/jenny/linnake/rojut/guard_sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
