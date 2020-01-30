inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(10);
    set_name("wizard");
    set_short("A wizard");
    set_long("This is a healer. He will most likely heal himself in combat.\n");
    set_al(50);
    set_aggressive(0);
    set_spell_chance(50, "exs fla grs");
    set_spell_chance(50, "exs sol grs");
    set_skill("cast essence", 80);
    set_skill("cast fire", 80);
    set_skill("cast earth", 80);
    set_skill("cast grasp", 80);
    set_skill("mana control", 80);
}

