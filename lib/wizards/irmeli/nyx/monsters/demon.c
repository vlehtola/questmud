inherit "obj/monster";

reset(arg) {
    object armour;
        ::reset(arg);
    if(arg) { return; }
    set_level(40);
    call_other(this_object(), "set_name", "demon");
    call_other(this_object(), "set_alias", "demon");
    call_other(this_object(), "set_short", "Blood-red Demon of the Morfeus (resurrected)");
    call_other(this_object(), "set_long", "The blood-red demon of the Morfeus has been resurrected by the master raiser\n"+
                                          "of the spirits. The demon of the morfeus has blood-red, scabby skin, two big\n"+
                                          "wings, growing from its back and tall, pronged tail. Its red, foxy eyes are\n"+
                                          "big and round-shaped. The body of the demon is muscular.\n");
    set_race("demon");
    set_gender(1);
    call_other(this_object(), "set_al", -40);
    set_spell_chance(90, "exs ssh grs");
    set_spell_chance(90, "exs brr grs");
    set_skill("cast ice", 90);
    set_skill("cast essence", 90);
    set_skill("cast acid", 90);
    set_skill("cast grasp", 90);
    set_skill("quick spelling", 50);
    set_skill("mana control", 50);
    call_other(this_object(), "set_aggressive", 1);
    set_block_dir("west");
    set_block_message("Demon blocks your pitiful attempt to flee.\n");
    set_experience(666);
}
