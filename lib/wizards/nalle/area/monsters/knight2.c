inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_name", "knight");
    call_other(this_object(), "set_alias", "dequan");
    call_other(this_object(), "set_short", "A Dequan Knight, order of the Pine");
    call_other(this_object(), "set_long", "This is a higher ranking Dequan knight. He is wearing a\n" +
                                          "suit made of shining armour, and wielding a beautiful\n" +
                                          "weapon. The knight looks like a good fighter.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    

    armour = clone_object("/wizards/nalle/area/eq/knarmour");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/eq/morningstar");
    move_object(weapon, this_object());
    init_command("wield morningstar");
}

