inherit "obj/monster";

reset(arg) {

    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
set_level(50);
set_name("healer");
set_max_hp(query_max_hp() * 5);
set_hp(query_max_hp());

set_alias("hypnos");
set_short("Hypnos The wicked healer of Nyx");
set_long("This is the personal healer of Nyx. He represents the first generation offspring\n"
         "of Nyx. He will make sure that Nyx dies only over his dead body.\n");
set_al(-50);
    set_aggressive(1);
    set_extra(1);
    set_skill("cast divine", 80);
    set_skill("cast heal", 80);
    set_skill("cast major", 80);
    set_skill("channel", 80);
}

extra() {
    string spell_words, target_name;
    target_name = "nyx";
    spell_words = "chl hea mjr";

  /* Must have only half hp left, random 100 must be lower than 50 and
     must not be stunned to start casting. */

    if (!query_spell() && random(100) > 50 && query_hp() < query_max_hp() / 2 &&
        !this_object()->query_stunned()) {
            spell = clone_object("obj/spell");
            spell->start_spell(spell_words + " at " + target_name);

    }
}