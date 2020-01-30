inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object cloak, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(60);
    set_name("High priest");
    set_alias("priest");
    set_short("The Black Circle's high priest");
    set_long("As the priest is wearing the unholy symbol of Morai the Betrayer, you judge him to be a rather nasty individual.\n");
    set_al(-150);
    set_aggressive(1);
    set_extra(1);
    set_spell_chance("chl hrm rea", 50);
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast true", 80);
    set_skill("channel", 80);
    set_skill("cast harm", 80);
    set_race("human");
    set_log();

    weapon = clone_object("/wizards/tiergon/eq/hpmace");
    move_object(weapon, this_object());
    init_command("wield mace"); 
  
    cloak = clone_object("/wizards/tiergon/eq/scloak");
    move_object(cloak, this_object());
    init_command("wear cloak");

}

extra() {
    string spell_words, target_name;
    target_name = "priest";
    spell_words = "chl hea rea";

    if (!query_spell() && query_hp() < query_max_hp()/ 2 &&
        !this_object()->query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);
    }
}
