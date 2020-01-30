inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 29);
    call_other(this_object(), "set_name", "Priest");
    call_other(this_object(), "set_alias", "priest");
    call_other(this_object(), "set_short", "A tall priest, clad in white robes");
    call_other(this_object(), "set_long", "The priest is a tall man. At the moment he seems to\n" +
                                          "be teaching religious matters to the Dequan Knights.\n");
    call_other(this_object(), "set_al", 10);
    set_log();
    call_other(this_object(), "set_aggressive", 0);


    armour = clone_object("/wizards/nalle/area/eq/prrobes");
    move_object(armour, this_object());
    init_command("wear robes");

    weapon = clone_object("/wizards/nalle/area/eq/knstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
}

