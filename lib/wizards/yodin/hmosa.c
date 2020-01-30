inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(50);
    set_name("wizard");
    set_short("MaD WiZaRd.");
    set_long("ihQ pihQ skeleloni tappaa kaig.\n");
    set_al(50);
    set_aggressive(0);
    set_extra(1);
    set_skill("cast divine", 100);
    set_skill("cast heal", 100);
    set_skill("cast major", 100);
    set_skill("channel", 100);
}

extra() {
    string spell_words, target_name;
    target_name = "wizard";
    spell_words = "chl hea mar";
    if (!query_spell() && random(100) > 50 && query_hp() < query_max_hp() / 2 &&
        !this_object()->query_stunned()) {
            spell = clone_object("guilds/obj/spell");
            move_object(spell, this_object());
            spell->start_spell(spell_words + " at " + target_name);
}
}
