inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 20);
    call_other(this_object(), "set_name", "knight");
    call_other(this_object(), "set_alias", "dequan");
    call_other(this_object(), "set_short", "A Dequan Knight is training here");
    call_other(this_object(), "set_long", "This knight is training his sword-techniques\n" +
                                          "on a sandbag. He has the emblem of the order\n" +
                                          "of the Pine on his armour.\n");
    call_other(this_object(), "set_al", 7);
    call_other(this_object(), "set_aggressive", 0);


    armour = clone_object("/wizards/nalle/area/eq/knarmour");
    move_object(armour, this_object());
    init_command("wear armour");
 
    weapon = clone_object("/wizards/nalle/area/eq/knsword");
    move_object(weapon, this_object());
    init_command("wield sword");
}
