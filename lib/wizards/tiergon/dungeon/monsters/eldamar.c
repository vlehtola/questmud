inherit "obj/monster";

reset(arg) {
    string a_chat_str;
    object robes;
    object dagger;
    object armour;
    ::reset(arg);
    if (arg) { return; }
    set_level(88);
    set_undead(1);
    set_name("Eldamar");
    set_alias("eldamar");
    set_short("Eldamar the Archlich");
    set_race("lich");
    set_long("\n");
    set_al(-120);
    set_log();
    set_aggressive(1);
    set_spell_chance(75, "exs brr strm");
    set_mage(1);
    set_skill("cast essence", 100);
    set_skill("cast ice", 100);
    set_skill("cast storm", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 100);
    set_move_at_random(0);
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Eldamar's dried skin creaks as he moves his hands in the arcane gestures of spellcasting.\n";
    }
    load_a_chat(10, a_chat_str);

    dagger = clone_object("/wizards/tiergon/eq/elddagger");
    move_object(dagger, this_object());
    init_command("wield dagger");

    armour = clone_object("/wizards/tiergon/eq/eldmail");
    move_object(armour, this_object());
    init_command("wear mail");

    robes = clone_object("/wizards/tiergon/eq/eldrobes");
    move_object(robes, this_object());
    init_command("wear robes");
}

