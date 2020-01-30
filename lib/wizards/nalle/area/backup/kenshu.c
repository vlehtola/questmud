inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_name("kenshu");
    set_alias("cleric")
    set_short("Kenshu, Darvox's faithful cleric.");
    set_long("This is Kenshu, Darvox's faithful cleric.\n");
    set_exp(890000)
    set_skill("dodge", 77);
    set_al(21);
    set_aggressive(0);
}

special() {
    string spell_words, target_name;
    target_name = "darvox";
    spell_words = "chl mjr hea";

    if (!query_spell() && random(100) > 50 && query_hp() < query_max_hp() / 2 &&
        !query_uncon() && !query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);
        }
    }
}
