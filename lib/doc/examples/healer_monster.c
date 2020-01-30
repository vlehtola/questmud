inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(10);
    set_name("healer");
    set_short("A healer.");
    set_long("This is a healer. He will most likely heal himself in combat.\n");
    set_al(50);
    set_aggressive(0);
    set_extra(1);
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast major", 80);
    set_skill("channel", 80);
}

extra() {
    string spell_words, target_name;
    target_name = "healer";
    spell_words = "chl hea mar";
  /* Must have only half hp left, random 100 must be lower than 50 and
     must not be stunned to start casting. */

    if (!query_spell() && random(100) > 50 && query_hp() < query_max_hp() / 2 &&
        !this_object()->query_stunned()) {
            spell = clone_object("guilds/obj/spell");
            move_object(spell, this_object());
            spell->start_spell(spell_words + " at " + target_name);
    }
}
