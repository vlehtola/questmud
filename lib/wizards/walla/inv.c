inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    set_level(25);
    set_name("stalker");
    set_alias("monster");
    set_short("");
    set_long("This invisible stalker hides out in the dark backstabbing you every now and then")
    set_al(-10);
    set_spell_chance(100, "exs fla arr");
    set_aggressive(1);
    set_skill("cast essence", 100);
    set_skill("cast fire", 100);
    set_skill("cast arrow", 100);
    set_skill("mana control", 100);
    set_skill("chanting", 69);
    set_dead_ob(this_object());
}
