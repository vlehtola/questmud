inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_log();
    set_level(10);
    set_name("healer");
    set_short("healer");
    set_long("This is a healer. He will most likely heal himself in combat.\n");
    set_al(50);
    set_aggressive(0);
    set_extra(1);
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast major", 80);
    set_skill("channel", 80);
    set_skill("cast essence", 100);
    set_skill("cast electric", 100);
    set_skill("cast illusion", 100);
    set_skill("mana control", 100);
    set_skill("quick chant", 100);
}

extra() {
    string spell_words, target_name;
    target_name = "test";
    spell_words = "exs zzt ils";

    if (!query_spell() && random(100) > 50 && !this_object()->query_stunned()) {
            spell = clone_object("guilds/obj/spell");
            move_object(spell, this_object());
            spell->start_spell(spell_words + " at " + target_name);
    }
}

