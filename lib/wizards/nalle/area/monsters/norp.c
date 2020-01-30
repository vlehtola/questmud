inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "Norp");
    call_other(this_object(), "set_alias", "norp");
    call_other(this_object(), "set_short", "Norp Alemouth the barkeeper");
    call_other(this_object(), "set_long", "This is a Norp Alemouth, the barkeeper of the Inn of the\n" +
                                          "Three Bears. He is constantly smiling happily and takes\n" +
                                          "sips of ale every now and then.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);


    armour = clone_object("/wizards/nalle/area/eq/norparmour");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/eq/staff");
    move_object(weapon, this_object());
    init_command("wield staff");
}
