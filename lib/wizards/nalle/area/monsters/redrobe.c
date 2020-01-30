inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 20);
    set_mage(1);
    call_other(this_object(), "set_name", "Mage");
    call_other(this_object(), "set_alias", "mage");
    call_other(this_object(), "set_short", "A red-robed mage");
    call_other(this_object(), "set_long", "This is one of Darvox's apprentices. He is\n" +
                                          "wearing red robes. which conceal even his face.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);


    armour = clone_object("/wizards/nalle/area/eq/magcloak");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/eq/magstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
}

