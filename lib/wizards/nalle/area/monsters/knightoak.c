inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 20);
    call_other(this_object(), "set_name", "knight");
    call_other(this_object(), "set_alias", "dequan");
    call_other(this_object(), "set_short", "A Dequan Knight, order of the Oak");
    call_other(this_object(), "set_long", "This is a quite high ranking Dequan knight. His equipment\n" +
                                          "is nevertheless similar to the equipment the knight of the\n" +
                                          "Pine have, only with a different emblem.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);


    armour = clone_object("/wizards/nalle/area/eq/knarmour");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/eq/morningstar");
    move_object(weapon, this_object());
    init_command("wield morningstar");
}
