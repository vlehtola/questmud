inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(40);
    set_undead(1);
    set_name("gaspard");
    set_alias("priest");
    set_short("Gaspard DeLouca the priest of Morai");
    set_long("Gaspard was Eldamar's most faithful apprentice before his death, and it looks like he has continued to serve his lord even in death as a spectral minion.\n");
    set_al(-100);
    set_aggressive(1);
    set_extra(1);
    set_skill("cast divine", 100);
    set_skill("cast heal", 100);
    set_skill("cast true", 100);
    set_skill("channel", 100);
}

extra() {
    string spell_words, target_name;
    object ob;
    target_name = "eldamar";
    spell_words = "chl hea rea";

    ob = present("eldamar", environment());
    if(!ob) return;
    if (!query_spell() && random(100) > 30 && ob->query_hp() < ob->query_max_hp() && !this_object()->query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);
    }
}
