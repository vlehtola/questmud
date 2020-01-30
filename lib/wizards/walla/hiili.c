inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(50);
    set_name("healer");
    set_short("A healer.");
    set_long("This is a healer. He will most likely heal himself in combat.\n");
    set_al(0);
    set_aggressive(0);
}
 
special() {
    string spell_words, target_name;
    target_name = lower_case(this_object()->query_name());
    spell_words = "chl hea rea";
 
    if (!query_spell() && random(100) > 50 && query_hp() < query_max_hp() / 1 &&
        !query_uncon() && !query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);
        }
    }
 
 
