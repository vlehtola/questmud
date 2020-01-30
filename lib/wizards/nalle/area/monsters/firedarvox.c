inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    call_other(this_object(), "set_level", 45);
    set_mage(1);
    call_other(this_object(), "set_name", "Darvox");
    call_other(this_object(), "set_alias", "darvox");
    call_other(this_object(), "set_short", "Darvox, the master of the elements");
    call_other(this_object(), "set_long", "This is Darvox, one the most dreaded being in the realm,\n" +
                                          "the undisputed leader of the black-robed magic users. He is fairly\n" +
                                          "young and tall. The air around him crackles with magical energy.\n");
    call_other(this_object(), "set_al", -6);
    set_spell_chance(90, "exs fla blt");
    call_other(this_object(), "set_aggressive", 1);
    call_other(this_object(), "set_exp", 456789);
    set_skill("cast essence", 99);
    set_skill("cast fire", 99);
    set_skill("knowledge of heat", 99);
    set_skill("cast bolt", 99);
    set_skill("mana control", 99);
    set_skill("chanting", 88);
    set_skill("blades", 88);
    set_block_dir("up");

    weapon = clone_object("/wizards/nalle/area/eq/darvdagger");
    move_object(weapon, this_object());
    init_command("wield dagger");
}














