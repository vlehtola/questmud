inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(25);
    set_name("initiate");
    set_alias("member");
    set_short("");
    set_long("This looks like a typical Ku Klux Klanien. He is all dressed up in a white dress\n" +
                     "and a hood, which alltogether cover up all of the members body. He hushes\n" +
"you\n" +
                     "and reminders you to go away.");
    set_al(-10);
    set_spell_chance(100, "exs fla arr");
    set_aggressive(0);
    set_skill("cast essence", 100);
    set_skill("cast fire", 100);
    set_skill("cast arrow", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 69);
    set_dead_ob(this_object());
}
